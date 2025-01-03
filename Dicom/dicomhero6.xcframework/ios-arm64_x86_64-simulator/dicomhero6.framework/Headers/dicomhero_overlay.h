/*
Copyright 2005 - 2019 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcOverlay__INCLUDED_)
#define dicomheroObjcOverlay__INCLUDED_

#import <Foundation/Foundation.h>
#include "dicomhero_macros.h"

/// \enum DicomheroOverlayType
///
/// \brief Defines the Overlay type.
///
///////////////////////////////////////////////////////////////////////////////
typedef NS_ENUM(unsigned int, DicomheroOverlayType)
{
    DicomheroOverlayTypeGraphic = 0,  ///< The overlay is a superimposed graphic
    DicomheroOverlayTypeROI = 1,      ///< 8The overlay specifies a region of interest
};

@class DicomheroImage;


///
/// \brief Represents a DICOM overlay.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroOverlay: NSObject

{
    @public
    define_dicomhero_object_holder(Overlay);
}

    -(id)initWithDicomheroOverlay:define_dicomhero_parameter(Overlay);

    /// \brief Initializer.
    ///
    /// \param type          the overlay type
    /// \param subType       the overlay sub type.
    ///                      Defined Term that identifies  the intended purpose of
    ///                       the Overlay Type. See Section C.9.2.1.3 for further
    ///                       explanation.
    /// \param firstFrame    first DICOM image related to this overlay (zero-based)
    /// \param zeroBasedOriginX the zero based horizontal position within the
    ///                       DICOM image
    /// \param zeroBasedOriginY the zero based vertical position within the
    ///                       DICOM image
    /// \param label          overlay label
    /// \param description    overlay description
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithType:(DicomheroOverlayType)type subType:(NSString*)subType firstFrame:(unsigned int)firstFrame zeroBasedOriginX:(int)zeroBasedOriginX zeroBasedOriginY:(int)zeroBasedOriginY label:(NSString*)label description:(NSString*)description;

    -(void)dealloc;


    ///
    /// The overlay type.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) DicomheroOverlayType type;

    ///
    /// The overlay subtype.
    ///
    /// Defined Term that identifies  the intended purpose of the Overlay Type.
    /// See Section C.9.2.1.3 for further explanation.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* subType;

    ///
    /// Overlay label.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* label;

    ///
    /// Overlay description.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* description;

    ///
    /// The zero based number of the first frame (Image) related to this
    ///  overlay,
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) unsigned int firstFrame;

    ///
    /// The number of bitmaps stored in the overlay.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) unsigned int framesCount;

    ///
    /// The zero-based horizontal position of the overlay bitmap into the
    ///  related DICOM image.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) int zeroBasedOriginX;

    ///
    /// The zero-based vertical position of the overlay bitmap into the
    ///  related DICOM image.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) int zeroBasedOriginY;

    ///
    /// \brief Return the ROI area if present, otherwise set pError to
    ///         DicomheroMissingTagError.
    ///
    /// \param pError      set to an error object if an error occurs
    /// \return the ROI area in pixels
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(unsigned int) getROIArea:(NSError**)pError
       DICOMHERO_NONNULL_ERROR;

    ///
    /// \brief Return the ROI mean if present, otherwise set pError to
    ///         DicomheroMissingTagError.
    ///
    /// \param pError      set to an error object if an error occurs
    /// \return the ROI mean value
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(double) getROIMean:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    ///
    /// \brief Return the ROI standard deviation if present, otherwise set pError
    ///         to DicomheroMissingTagError.
    ///
    /// \param pError      set to an error object if an error occurs
    /// \return the ROI standard deviation
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(double) getROIStandardDeviation:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    ///
    /// \brief Return one of the overlay bitmaps if present, otherwise set pError
    ///         DicomheroDataSetImageDoesntExistError.
    ///
    /// \param frameNumber    the number of frame to retrieve (zero based)
    /// \param pError         set to an error class in case of error
    /// \return the requested overlay image
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroImage*) getImage:(unsigned int)frameNumber error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    ///
    /// \brief Set the number of pixels in the ROI area.
    ///
    /// \param roiArea number of pixels in the ROI area
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void) setROIArea:(unsigned int)roiArea;

    ///
    /// \brief Set the mean value of the pixels in the ROI area.
    ///
    /// \param roiMean mean value of the pixels in the ROI area
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void) setROIMean:(double)roiMean;

    ///
    /// \brief Set the standard deviation of the value of the pixels in the ROI
    ///        area.
    ///
    /// \param standardDeviation standard deviation of the value of the pixels in
    ///                          the ROI area
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void) setROIStandardDeviation:(double)standardDeviation;

    ///
    /// \brief Add a bitmap to the overlay.
    ///
    /// \param frameNumber a zero based frame (relative to the overlay frames)
    /// \param image       the image for the overlay
    /// \param pError      set to an error object if an error occurs
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void) setImage:(unsigned int)frameNumber image:(DicomheroImage*)image error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;


@end


#endif // dicomheroObjcOverlay__INCLUDED_


