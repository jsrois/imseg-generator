### Image Segmentation Generator

#### Installation

Notice this requires `cmake` (v. 3.5) and `opencv` (v. 2.4) to be installed.

```
mkdir build
cd build
cmake ..
make
```

#### Usage


```
./imseg-generator <input-image> <input-annotation> <output-image>
```

Input annotations must be written in a 2-column format, where each row correspond to each of the points in the segmentation mask, e.g:

```
301.320 93.960
305.720 94.510
306.540 95.060
307.090 99.180
...
```




