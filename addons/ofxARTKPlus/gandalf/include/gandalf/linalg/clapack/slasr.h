/**************************************************************************
*
* File:          $RCSfile: slasr.h,v $
* Module:        CLAPACK function
* Part of:       Gandalf Library
*
* Revision:      $Revision: 1.2 $
* Last edited:   $Date: 2005/02/25 09:30:25 $
* Author:        $Author: pm $
* Copyright:     Modifications (c) 2000 Imagineer Software Limited
*
* Notes:         
* Private func:  
* History:       Modified from original CLAPACK source code 
*
**************************************************************************/

#ifndef _GAN_SLASR_H
#define _GAN_SLASR_H

#include <gandalf/common/misc_defs.h>
#include <gandalf/linalg/linalg_defs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* only declare this function locally if there is no LAPACK installed */
#if !defined(HAVE_LAPACK) || defined(FORCE_LOCAL_LAPACK)
Gan_Bool gan_slasr(Gan_LapackPlaneRotationType side,
                   Gan_LapackPivotType pivot,
                   Gan_LapackPlaneRotationDirection direct,
                   long m, long n, float *c, float *s, float *a, long lda);
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _GAN_SLASR_H */

