### RSL v1.50- with additional fixes
Cloned from: http://pileus.org/aweather/files/rsl-v1.50.tar.gz and modified to build on a modern Linux distro.

Noteworthy changes in this fork:
-------------------------------
 - Sept 2024 - Fixed issues with building on Arch Linux, merged in fixes for wsr88d from https://github.com/adokter/rsl/
 - Dec 2024 - Added support for 'clutter filter power removed' NEXRAD volume, updated wsr88d_locations.dat to be in sync with live sites.
 - Feb 2025 - Fixed multi-threading race conditions in wsr88d decoding, updated to ensure all radar sites have a state code in the `wsr88d_locations.dat` file.

OVERVIEW
--------
This is the README file for the Radar Software Library (RSL).

The author of RSL is John H. Merritt.

RSL is maintained by Bart Kelley <Bartie.L.Kelley@nasa.gov>.

What is RSL?
   This software manipulates NexRad, Lassen, UF, sigmet, kwajalein,
toga, RAPIC, RADTEC, and mcgill radar formats.

The radar data is used by the NASA TRMM Office to produce rain
and climatological products.  This software
can ingest an entire input data file, representing it in RAM as it
is on disk, manipulate the data and produce simple images.  The intent
of this library is to provide you with the tools to manipulate the 
data.  With those tools you gain easy access to the different radar
fields (reflectivity, velocity, spectral width, etc.) and ancilliary
information (headers: time, beam width, angles, etc).  And, with the
tools you can code a scientific application that are radar format
independent.

COPYRIGHT NOTICE:
    NASA/TRMM, Code 910.1.
    This is the TRMM Office Radar Software Library.
    Copyright (C) 1996-1999
            John H. Merritt
            SM&A Corp.
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


System Requirements:
  Linux, Mac OS X 10.5.

Note: RSL is not supported on Microsoft Windows.

Memory Requirements:
  16 Mbytes of RAM just to ingest the data.  Plus any for your application.
  If you expect to use the TSDIS toolkit component, which requires the HDF
  library, then you'll need at least 64 MB RAM!

Software Environment.  Additional libraries may be needed for building
or linking, especially if you plan to use the TSDIS Toolkit and HDF.
All the source for wsr88d, lassen, tg, nsig, mcgill, kwajalein,
etc, are included in librsl.a and librsl.so.  RSL works on big or
little endian machines.  HP, SUN, SGI are examples of big endian machines.
Intel 386/486/Pentium is an example of a little endian machine.

Additional software needed for executing RSL code is listed below.
Note, RSL can be built without TSDIS toolkit and without HDF and
without PKWARE support.
	
  gcc (GNU cc compiler)   Normal cc or acc (sun) will work.  Not required,
                          but, you do need an ansi compilier.

  gzip (GNU compress)     Available via anon ftp to ftp.uu.net.  Unpacking.
                          Input and output filters for auto un/compressing.


  make (GNU make)         GNU make version 3.76. Standard make on SGI
                          IRIX 6.2 doesn't work.  It's a good idea
                          to have GNU make (GNU tar too).

  pbmplus (Jef Poskanzer) Available via anon ftp to ftp.uu.net.  This is 
                          used when making GIF, PPM, PBM, PGM, PICT, etc.
                          images.  Output via pipes.  Required for executing
                          your RSL application, if you plan to output images.
                          This is not required when 
                          linking your application with the RSL.
                          You only need ppmtogif and ppmtopict.

  PKWARE Data             Version 1.11.  Needed for the RAPIC ingest.
  Compression library.    Call PKWARE, Inc. at 414-354-8699 or via
                          http://www.pkware.com.
                          
Example mainlines are provided in the directory examples. 

INSTALLATION INSTRUCTIONS
--------------------------

Arch Linux: Install from the AUR - https://aur.archlinux.org/packages/rsl-git

1.  Unpack the GNU compressed tar archive, example:

     `tar -xzf rsl-v1.43.tgz`
       or
     `zcat rsl-v1.43.tgz | tar xf -`

2. If you DON'T want LASSEN capability or you find that your system
   can not compile the lassen routines, you must edit acconfig.h and
   change '#define HAVE_LASSEN 1' to '#undef HAVE_LASSEN'.

3. configure
   `make install`    -- Installs the RSL library, and then installs
                      `any_to_gif` and `any_to_uf`.

NOTE: You can specify the --prefix=/some/other/dir as an option to
      the configure command.  This will install the librsl.so there
      and will install the examples there.  Also, when resolving
      whether you have hdf, tsdistk, etc. the --prefix instructs
      configure to look in the prefix/lib directory for those libraries.
	  The examples installed are any_to_gif and any_to_uf.


BUILDING APPLICATIONS
---------------------
Place the following line in your C code:

#include "rsl.h"

And link your application with:

   -lrsl -lm

If you're on a SUN, you might have to specify:

   -lrsl -lnsl -lm

If you want HDF and TSDIS toolkit libraries (the link line looks messy):

   setenv TSDISTK /usr/local/toolkit  (or your top-level directory name)

   -lrsl -L/usr/local/hdf/lib  -L/usr/local/toolkit/lib \
   -ltsdistk -lmfhdf -ldf -ljpeg -lz -lm

   Be sure to substitute the appropriate -L specification for the HDF
   and the TSDISTK library paths on your system.

PROBLEMS
--------

1. If you don't have ppmtogif nor ppmtopict, you can still make images.  The
   images will be PPM files.  Create two commands called 'ppmtogif' and
   'ppmtopict' that consists of the following two lines:
```bash
#!/bin/csh -f
cat
```
   Make these new commands executable and
   place them in a directory that is in your $PATH.  No translation
   of PPM will happen and you can use 'xv', for instance, to view
   the files.

2. Linking on SUN running SunOS 5.4, you may need to add '-lnsl' to
   the link line to link your application.  'libnsl.{a,so}' is where
   the 'xdr' routines reside.

3. On our HP, gcc cannot build a shared library in one fell swoop.  You
   must use the '-v' option.  You'll get an error similiar to that shown
   in the following 'make' excerpt.


```bash
gcc -v -shared -W1,-soname,librsl.so.1 -o librsl.so.1.17 rapic_to_radar.o rapic.tab.o lex.rapic.o rapic_routines.o radar.o volume.o image_gen.o cappi.o fraction.o read_write.o farea.o range.o radar_to_uf.o uf_to_radar.o lassen_to_radar.o wsr88d_to_radar.o carpi.o cube.o sort_rays.o toga_to_radar.o gts.o histogram.o ray_indexes.o anyformat_to_radar.o get_win.o endian.o mcgill_to_radar.o mcgill.o interp.o toga.o lassen.o  wsr88d.o wsr88d_get_site.o gzip.o prune.o reverse.o fix_headers.o radar_to_hdf_1.o radar_to_hdf_2.o nsig_to_radar.o nsig.o nsig2_to_radar.o hdf_to_radar.o toolkit_memory_mgt.o africa_to_radar.o africa.o
Reading specs from /opt/hppd/lib/gcc/gcc-lib/hppa1.1-hp-hpux9.05/2.7.2.1/specs
gcc version 2.7.2.1
 /opt/hppd/lib/gcc/gcc-lib/hppa1.1-hp-hpux9.05/2.7.2.1/ld -b -o librsl.so.1.17 -L/opt/hppd/lib/gcc/gcc-lib/hppa1.1-hp-hpux9.05/2.7.2.1 -L/opt/hppd/lib/gcc rapic_to_radar.o rapic.tab.o lex.rapic.o rapic_routines.o radar.o volume.o image_gen.o cappi.o fraction.o read_write.o farea.o range.o radar_to_uf.o uf_to_radar.o lassen_to_radar.o wsr88d_to_radar.o carpi.o cube.o sort_rays.o toga_to_radar.o gts.o histogram.o ray_indexes.o anyformat_to_radar.o get_win.o endian.o mcgill_to_radar.o mcgill.o interp.o toga.o lassen.o wsr88d.o wsr88d_get_site.o gzip.o prune.o reverse.o fix_headers.o radar_to_hdf_1.o radar_to_hdf_2.o nsig_to_radar.o nsig.o nsig2_to_radar.o hdf_to_radar.o toolkit_memory_mgt.o africa_to_radar.o africa.o
/bin/ld: DP-Relative Code in file /usr/tmp/cca11778.o - Shared Library must be Position-Independent 
collect2: ld returned 1 exit status
make: *** [librsl.so.1.17] Error 1
```

   Take the 'ld' command that is shown, the second of the two commands,
   and execute it directly at the Unix prompt.  It will create the
   shared library. I don't get it, but, it works.  My guess is that
   the 'gcc' command is doing something that is not shown.  What is
   shown are the correct commands.  Go figure.


Contributions
-------------
Dave Wolff - Most of the specifications for the functionality and feedback
             during debugging.
Mike Kolander - The HDF, Mcgill and kwaj to radar routines.
Alan McConnell - The toga_to_radar routine.
Dennis Flanigan - New sorting code. Echo top height routines. Vertical
                  structure code.
Thuy Nguyen - Bug fixes and testing.
Paul Kucera - Testing, bug reports and SIGMET code.
Michael Whimpy - BMRC, Austrailia.  Lassen modifications.
Don Burrows - The edge_to_radar routine.

QUESTIONS
---------

Contact the TRMM Office help at gsfc-rsl-help@lists.nasa.gov

UPDATING
--------
Some files in this repo need to be synced from internet sources.
- `wsr88d_locations.dat`: This file contains a list of NEXRAD radar sites.
   Run `helpers/regenerate-wsr88d_locations-file-from-web-source.py` to regenerat this file with data from https://www.ncei.noaa.gov/access/homr/.

RELATED PROJECTS
----------------
Note - This is not an endorsement of the projects or the programs listed below, but a list of related projects that can be used as a known-working NEXRAD Level 2 decoder.
- Online NEXRAD Level 2 viewer: https://radar.quadweather.com/
- Python NEXRAD Level 2 decoding library: https://github.com/ARM-DOE/pyart/blob/main/pyart/io/nexrad_level2.py#L66
