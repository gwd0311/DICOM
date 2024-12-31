/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcPersonName__INCLUDED_)
#define dicomheroObjcPersonName__INCLUDED_

#import <Foundation/Foundation.h>
#include "dicomhero_macros.h"


///
/// \brief Stores a person name (in alphabetic, ideographic and phonetic
///        forms).
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroPersonName: NSObject

{
    @public
    define_dicomhero_object_holder(PersonName);
}

    -(void)dealloc;

    -(id)initWithDicomheroPersonName:define_dicomhero_parameter(PersonName);

    /// \brief Constructor.
    ///
    /// Initialize the PersonName structure with the specified values.
    ///
    /// \param alphabeticRepresentation  The alphabetic representation of the
    ///                                  person name
    /// \param ideographicRepresentation The ideographic representation of the
    ///                                  person name. Can be left empty
    /// \param phoneticRepresentation    The phonetic representation of the
    ///                                  person name. Can be left empty
    /// \return the object's id
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithAlphabeticRepresentation:(NSString*)alphabeticRepresentation
                        ideographicRepresentation:(NSString*)ideographicRepresentation
                        phoneticRepresentation:(NSString*)phoneticRepresentation;

    @property (readonly) NSString* alphabeticRepresentation;         ///< The alphabetic representation of the Person Name
    @property (readonly) NSString* ideographicRepresentation;        ///< The ideographic representation of the Person Name
    @property (readonly) NSString* phoneticRepresentation;           ///< The phonetic representation of the Person Name

@end

#endif // dicomheroObjcPersonName__INCLUDED_
