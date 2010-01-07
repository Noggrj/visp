/****************************************************************************
 *
 * $Id$
 *
 * Copyright (C) 1998-2010 Inria. All rights reserved.
 *
 * This software was developed at:
 * IRISA/INRIA Rennes
 * Projet Lagadic
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * http://www.irisa.fr/lagadic
 *
 * This file is part of the ViSP toolkit.
 *
 * This file may be distributed under the terms of the Q Public License
 * as defined by Trolltech AS of Norway and appearing in the file
 * LICENSE included in the packaging of this file.
 *
 * Licensees holding valid ViSP Professional Edition licenses may
 * use this file in accordance with the ViSP Commercial License
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Contact visp@irisa.fr if any conditions of this licensing are
 * not clear to you.
 *
 * Description:
 * Conversion between tracker and visual feature.
 *
 * Authors:
 * Eric Marchand
 *
 *****************************************************************************/


/*!
  \file vpFeatureBuilder.h
  \brief  class  that defines conversion between tracker and visual feature
*/
#include <visp/vpConfig.h>

// tracker
#include <visp/vpDot.h>
#include <visp/vpDot2.h>
#include <visp/vpMeLine.h>


// forward projection tracker
#include <visp/vpPoint.h>
#include <visp/vpLine.h>
#include <visp/vpSphere.h>
#include <visp/vpCircle.h>
#include <visp/vpCylinder.h>

// visual feature
#include <visp/vpFeaturePoint.h>
#include <visp/vpFeaturePointPolar.h>
#include <visp/vpFeatureLine.h>
#include <visp/vpFeatureEllipse.h>
#include <visp/vpFeaturePoint3D.h>
#include <visp/vpFeatureThetaU.h>
#include <visp/vpFeatureTranslation.h>
#include <visp/vpFeatureVanishingPoint.h>

// others
#include <visp/vpImagePoint.h>

//pixel / meter conversion
#include <visp/vpCameraParameters.h>
#include <visp/vpPixelMeterConversion.h>
#include <visp/vpMeterPixelConversion.h>

#ifndef vpFeatureBuilder_H
#define vpFeatureBuilder_H

/*!
  \class vpFeatureBuilder

  \ingroup VsFeatureBuilder
  \brief Class that defines conversion between trackers and visual features.
*/
class VISP_EXPORT vpFeatureBuilder
{
public:
  // create vpFeaturePoint feature
  static void create(vpFeaturePoint &s, const vpCameraParameters &cam,
		      const vpDot &d) ;
  static void create(vpFeaturePoint &s, const vpCameraParameters &cam,
		      const vpDot2 &d) ;
  static void create(vpFeaturePoint &s, const vpCameraParameters &cam,
		      const vpImagePoint &t) ;
  static void create(vpFeaturePoint &s, const vpPoint &p) ;
  static void create(vpFeaturePoint &s,
		     const vpCameraParameters &goodCam,
		     const vpCameraParameters &wrongCam,
		     const vpPoint &p) ;

  // create vpFeaturePointPolar feature
  static void create(vpFeaturePointPolar &s, 
		     const vpCameraParameters &cam,
		     const vpDot &dot) ;
  static void create(vpFeaturePointPolar &s, 
		     const vpCameraParameters &cam,
		     const vpDot2 &dot) ;
  static void create(vpFeaturePointPolar &s, 
		     const vpCameraParameters &cam,
		     const vpImagePoint &iP) ;
  static void create(vpFeaturePointPolar &s, const vpPoint &p) ;
  static void create(vpFeaturePointPolar &s,
		     const vpCameraParameters &goodCam,
		     const vpCameraParameters &wrongCam,
		     const vpPoint &p) ;

  // create vpFeaturePoint3D feature
  static void create(vpFeaturePoint3D &s, const vpPoint &p ) ;

  // create vpFeatureLine feature
  static void create(vpFeatureLine &s, const vpLine &l ) ;
  static void create(vpFeatureLine &s, const vpCylinder &c, const int line) ;

  static  void create(vpFeatureLine &s,
		      const vpCameraParameters &cam,
		      const vpMeLine &mel) ;

  //! create vpFeatureEllipse feature
  static void create(vpFeatureEllipse &s, const vpCircle &c) ;
  static void create(vpFeatureEllipse &s, const vpSphere &sphere) ;
  static void create(vpFeatureEllipse &s,
		     const vpCameraParameters &cam,
		     const vpDot &d ) ;
  static void create(vpFeatureEllipse &s,
		     const vpCameraParameters &cam,
		     const vpDot2 &d ) ;


  /*!
      create vpFeatureVanishingPoint feature from the 2D coordinates of a point
      in the image plane
  */
  static void create(vpFeatureVanishingPoint &s, const vpPoint &p);
  /*!
    create vpFeatureVanishingPoint feature from 2 FeatureLine, ie lines in
    the image plane (error if the 2 lines are parallel)
  */
  static void create(vpFeatureVanishingPoint &s, const vpFeatureLine &l1, const vpFeatureLine &l2 );
  /*!
    create vpFeatureVanishingPoint feature from 2 Lines, (error if the 2
    lines are parallel in the image plane)
  */
  static void create(vpFeatureVanishingPoint &s, const vpLine &l1, const vpLine &l2 );



} ;

#endif

/*
 * Local variables:
 * c-basic-offset: 2
 * End:
 */
