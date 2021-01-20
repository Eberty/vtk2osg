# vtk2osg

## **Overview**

vtk2osg is a simple project that demonstrates the usage of [vtkActorToOSG
class](http://www.visbox.com/prajlich/vtkActorToPF/osg.html) created by
Michael Gronager.

This project contains a simple example to load a VTK file and visualize it in OSG viewer.

We also update the vtkActorToOSG class to use it in new versions of VTK and OSG. To use previous versions of OSG use the files available in the link above.

**Keywords:** OSG, VTK, vtkActorToOSG.

&nbsp;

### **License**

The source code is released under [GNU Library General Public License (LGPL)](https://www.gnu.org/licenses/lgpl-3.0.html)

**Maintainer:** Eberty Alves da Silva, <eberty.silva@hotmail.com>

The `vtk2osg` package has been tested under *Ubuntu 16.04 LTS*.

&nbsp;

## **Installation**

### **Dependencies**

The project depends on some external libraries:

* VTK
* OpenSceneGraph
* CMake

Please beware that `CMakeLists.txt` does not check for particular versions of
these libraries/tools (apart from CMake), so in case of some older versions the compilation might fail with magical errors.

#### **Building**

```sh
cd vtk2osg
mkdir build && cd build
cmake .. && make
cd ..
```

## **Usage**

```sh
 ./vtk2osg <input.vtk>
```

## **See also**

<https://github.com/piotrdomagalski/VTKToOSG>

## **Bugs & Feature Requests**

Please report bugs and request features using the [Issue Tracker](https://github.com/Eberty/vtk2osg/issues).
