# bayer2rgb for modern G++

## Copyright
 * Original codes from https://github.com/jdthomas/bayer2rgb
 * Jeff Thomas

## Copyleft
 * Me, Raphael Kim

## Introducing bayer2rgb 

bayer2rgb will convert naked (no header) raw bayer color space into RGB. 
There are several choices of interpolation (though they all look essentially the same to my eye). It can output tiff files, and can integrate with ImageMagick to output other formats.
I borrowed the bayer.c from the libdc1394 project, it is licensed under LGPL.
The interpolation algorithms used are described at external reference links.

# Additional requirements for MinGW-W64 (w/ msys2)
 * mman-win32 ( https://github.com/witwall/mman-win32 )
 * configure and build mman-win32, then install to msys2.

## Tested on 
 * Windows10 - MinGW-W64, g++ 9.2.0 (msys2 build)
 * Debian linux armhf, g++ 6.3.0 (raspberrypi3bp)
 * Debian linux aarch64, g++ 6.3.0

# How to build
Just type ... 
```
make
```


# Test running
```
    usage: ./bayer2rgb
       --input,-i     input file
       --output,-o    output file
       --width,-w     image width (pixels)
       --height,-v    image height (pixels)
       --bpp,-b       bits per pixel
       --first,-f     first pixel color: RGGB, GBRG, GRBG, BGGR
       --method,-m    interpolation method: NEAREST, SIMPLE, BILINEAR, HQLINEAR, DOWNSAMPLE, EDGESENSE, VNG, AHD
       --tiff,-t      add a tiff header
       --swap,-s      if bpp == 16, swap byte order before conversion
       --help,-h      this helpful message
```

# External reference links
1. http://sourceforge.net/projects/libdc1394
1. http://www.imagemagick.org/pipermail/magick-developers/2008-May/002953.html
1. http://scien.stanford.edu/class/psych221/projects/99/tingchen/main.htm


# ImageMagick Integration
Not supported.
