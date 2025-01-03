/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcFileStreamOutput__INCLUDED_)
#define dicomheroObjcFileStreamOutput__INCLUDED_

#import <Foundation/Foundation.h>
#import "dicomhero_baseStreamOutput.h"

///
/// \brief Represents an output file stream.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroFileStreamOutput : DicomheroBaseStreamOutput

    /// \brief Constructor.
    ///
    /// \param fileName the path to the file to open in write mode
    /// \param pError   set to a NSError derived class in case of error
    /// \return the object's ID
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithName:(NSString*)fileName error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

@end

#endif // dicomheroObjcFileStreamOutput__INCLUDED_


