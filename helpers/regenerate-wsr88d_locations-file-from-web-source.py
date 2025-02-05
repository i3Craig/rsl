#!/bin/python
"""
    NASA/TRMM, Code 910.1.
    This is the TRMM Office Radar Software Library.
    Copyright (C) 1996, 1997
            John H. Merritt
            Space Applications Corporation
            Vienna, Virginia

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
"""
# ChatGPT generated conversion tool designed to convert the file from https://www.ncei.noaa.gov/access/homr/file/nexrad-stations.txt
# into a format that RSL can use. Thus, running this script will update the supported radar locations.
# Documentation on the nexrad-stations.txt is available here: https://www.ncei.noaa.gov/access/homr/file/NexRad_Table.txt
# Overview page is here: https://www.ncei.noaa.gov/access/homr/
# Note: This script should be run from within the 'helpers' folder in this repository. If it isn't, the wsr88d_locations file won't be found and updated.
import re
import requests

def parse_format_a_line(line):
    """Parse a single line of Format A and extract fields."""
    return {
        'ncdcid': line[0:8].strip(),
        'icao': line[9:13].strip(),
        'name': line[20:50].strip(),
        'country': line[51:71].strip(),
        'state': line[72:74].strip(),
        'county': line[75:105].strip(),
        'lat': line[106:115].strip(),
        'lon': line[116:126].strip(),
        'elev': line[127:133].strip(),
        'utc': line[134:139].strip(),
        'stntype': line[140:190].strip(),
    }

def dms_from_decimal(decimal):
    """Convert decimal degrees to degrees, minutes, seconds."""
    decimal = float(decimal)
    is_negative = decimal < 0
    decimal = abs(decimal)
    degrees = int(decimal)
    minutes = int((decimal - degrees) * 60)
    seconds = round((decimal - degrees - minutes / 60) * 3600)
    if is_negative:
        degrees = -degrees
    return degrees, minutes, seconds

def format_b_line(data):
    """Format a single line of Format A data to Format B."""
    lat_d, lat_m, lat_s = dms_from_decimal(data['lat'])
    lon_d, lon_m, lon_s = dms_from_decimal(data['lon'])
    
    # Use ICAO as the site name, limit city to 15 characters, and pad or truncate as needed
    city = data['name'].replace(" ", "_")[:15]
    state = data['state']
    if(len(state.strip()) == 0):
        # If the state is blank, then compuate a two-character state code based on the country.
        # Here, we use the first letter of the country and the last letter.
        # If we just used the first two letters, "AZORES" would become "AZ", which is not good.
        state = data['country'][:1] + data['country'][-1:];
    elev = int(int(data['elev']) * 0.3048) # Convert feet to meters.

    return f"{data['ncdcid']}\t{data['icao']}\t{city}\t{state}\t{lat_d}\t{lat_m}\t{lat_s}\t{lon_d}\t{lon_m}\t{lon_s}\t{elev}"


def download_file(url, local_filename):
    """Download a file from a URL to a local path."""
    response = requests.get(url, stream=True)
    if response.status_code == 200:
        with open(local_filename, 'wb') as f:
            for chunk in response.iter_content(chunk_size=8192):
                f.write(chunk)
    else:
        raise Exception(f"Failed to download file from {url}. Status code: {response.status_code}")

def convert_format_a_to_b(input_file, output_file):
    """Convert a file from Format A to Format B."""
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        # Skip the first two lines (header)
        next(infile)
        next(infile)

        for line in infile:
            # Skip lines that are empty or too short to be valid
            #if len(line.strip()) < 190:
            #    continue
            
            # Parse Format A line
            data = parse_format_a_line(line)
            #print(f'parsed row data: {data}')
            
            # Convert to Format B
            format_b = format_b_line(data)

            #print(f'output row: {format_b}')
            # Write to the output file
            outfile.write(format_b + '\n')

# Example usage
url = 'https://www.ncei.noaa.gov/access/homr/file/nexrad-stations.txt'
input_file = 'nexrad-stations.txt'  # Downloaded file
output_file = '../wsr88d_locations.dat'  # Output file

# Download the input file
download_file(url, input_file)
print(f"Downloaded from '{url}' and saved it to '{input_file}'.")

# Convert the downloaded file
convert_format_a_to_b(input_file, output_file)
print(f"Output file saved to '{output_file}'.")

