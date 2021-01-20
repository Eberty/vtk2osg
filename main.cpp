/*
 * Copyright 2020 Eberty Alves
 */

#include <bits/stdc++.h>

#include <osgDB/ReadFile>

#include <osgGA/StateSetManipulator>
#include <osgGA/TrackballManipulator>

#include <osgUtil/Optimizer>

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgViewer/GraphicsWindow>

#include <vtkActor.h>
#include <vtkGenericDataObjectReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>

#include "vtk2osg.h"

bool endsWith(const std::string& str, const std::string& suffix) {
  return ((str.size() >= suffix.size()) && (str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0));
}

osgViewer::Viewer* createViewer() {
  osg::ref_ptr<osgGA::TrackballManipulator> manipulator = new osgGA::TrackballManipulator();
  manipulator->setAllowThrow(false);

  osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer();
  viewer->setUpViewInWindow(0, 0, 640, 480);
  viewer->getCamera()->setClearColor(osg::Vec4(48.0 / 255.0, 48.0 / 255.0, 48.0 / 255.0, 1.0));
  viewer->setCameraManipulator(manipulator);
  viewer->addEventHandler(new osgGA::StateSetManipulator(viewer->getCamera()->getOrCreateStateSet()));
  viewer->addEventHandler(new osgViewer::ThreadingHandler());
  viewer->addEventHandler(new osgViewer::StatsHandler());

  osgViewer::Viewer::Windows windows;
  viewer->getWindows(windows);
  if (!windows.empty()) {
    windows.front()->setWindowName("vtk2osg - Eberty Alves 2020");
  }

  return viewer.release();
}

int main(int argc, char** argv) {
  if (argc > 1 && endsWith(argv[1], ".vtk")) {
    osg::ref_ptr<osg::Node> node = NULL;

    vtkSmartPointer<vtkGenericDataObjectReader> reader = vtkSmartPointer<vtkGenericDataObjectReader>::New();
    reader->SetFileName(argv[1]);
    reader->Update();

    if (reader->IsFilePolyData()) {
      vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
      mapper->SetInputConnection(reader->GetOutputPort());

      vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);

      node = VTKActorToOSG(actor.Get());
    }

    if (node) {
      osgUtil::Optimizer optimizer;
      optimizer.optimize(node);

      osg::ref_ptr<osgViewer::Viewer> viewer = createViewer();
      viewer->setSceneData(node);
      return viewer->run();
    } else {
      std::cout << "Error on load " << argv[0] << " file." << std::endl;
    }
  } else {
    std::cout << "Usage: " << argv[0] << " <input.vtk>" << std::endl;
  }

  return 0;
}
