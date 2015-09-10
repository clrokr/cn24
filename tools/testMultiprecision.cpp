/*
 * This file is part of the CN24 semantic segmentation software,
 * copyright (C) 2015 Clemens-Alexander Brust (ikosa dot de at gmail dot com).
 *
 * For licensing information, see the LICENSE file included with this project.
 */  

#include <cn24.h>

#include <iostream>

typedef Conv::FloatDatum<23> fld;

int main(int argc, char** argv) {
  Conv::System::Init();
  LOGINFO << "Test.";
  
  Conv::FloatDatum<25> z(3);
  fld x, y = 3;
  x = 5;
  y -= x * 2;
  y -= z;
  LOGEND;
  return 0;
}