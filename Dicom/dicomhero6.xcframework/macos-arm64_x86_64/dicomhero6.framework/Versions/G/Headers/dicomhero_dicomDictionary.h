/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcDicomDictionary__INCLUDED_)
#define dicomheroObjcDicomDictionary__INCLUDED_

#import <Foundation/Foundation.h>

#import "dicomhero_dataset.h"

@class DicomheroTagId;

///
/// \brief Provides information about the tag's description and their default
///        data type (VR).
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroDicomDictionary: NSObject

    /// \brief Retrieve a tag's description.
    ///
    /// @param tagId     the tag's id
    /// @param pError    set to NSError derived class in case of error
    /// @return          the tag's description
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(NSString*)getTagDescription:(DicomheroTagId*)tagId error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a tag's minimum multiplicity value (the minimum number of
    ///        values that should be stored in the tag).
    ///
    /// @param tagId     the tag's id
    /// @param pError    set to NSError derived class in case of error
    /// @return          the minimum multiplicity value
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(unsigned int)getMultiplicityMin:(DicomheroTagId*)tagId error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a tag's maximum multiplicity value (the maximum number of
    ///        values that should be stored in the tag, 0=unlimited).
    ///
    /// @param tagId     the tag's id
    /// @param pError    set to NSError derived class in case of error
    /// @return          the maximum multiplicity value (0=unlimited)
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(unsigned int)getMultiplicityMax:(DicomheroTagId*)tagId error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a tag's step multiplicity value.
    ///
    /// @param tagId     the tag's id
    /// @param pError    set to NSError derived class in case of error
    /// @return          the step multiplicity value
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(unsigned int)getMultiplicityStep:(DicomheroTagId*)tagId error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a tag's default data type.
    ///
    /// @param tagId        the tag's id
    /// @param pError    set to NSError derived class in case of error
    /// @return          The tag's data type
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(DicomheroTagType)getTagType:(DicomheroTagId*)tagId error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Register a private tag.
    ///
    /// Private tags must have an odd group number and an id lower than or equal
    /// to 0xff.
    ///
    /// An unique company identifier must be specified for the private tags, so
    /// that when a private tag is used Dicomhero can reserve the proper range
    /// of private tags within the group. All the private tags belonging to the
    /// same organization should have the same unique company identifier.
    ///
    /// \param tagId                   the tag's id
    /// \param name                    the tag's name
    /// \param keyword                 the tag's keyword (used when generating
    ///                                XMLDOM objects)
    /// \param companyIdentifier       a string uniquely identifying the
    ///                                company responsible for the private tag
    /// \param vr                      the tag's VR
    /// \param multiplicityMin         minimum number of items in the tag
    /// \param multiplicityMax         maximum number of items in the tag
    /// \param multiplicityStep        the multiplicity step (usually 1)
    /// \param pError set to DicomheroDictionaryWrongPrivateTagError if the group 
    ///               or id is not valid.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(void)registerPrivateTag:(DicomheroTagId*)tagId name:(NSString*)name
                       keyword:(NSString*)keyword
             companyIdentifier:(NSString*)companyIdentifier
                            vr:(DicomheroTagType)vr
               multiplicityMin:(unsigned int)multiplicityMin
               multiplicityMax:(unsigned int)multiplicityMax
              multiplicityStep:(unsigned int)multiplicityStep
                         error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Return the size (in bytes) of the data type's elements
    ///
    /// @param dataType the data type for which the information is required
    /// @return the size of a single element, in bytes. 0 means that there isn't
    ///         a fixed size for the element
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(unsigned int)getWordSize:(DicomheroTagType)dataType;

    /// \brief Return the maximum size of the tags with the specified data type.
    ///
    /// @param dataType the data type for which the information is required
    /// @return         the maximum tag's size in bytes
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(unsigned int)getMaxSize:(DicomheroTagType)dataType;

@end

#endif // dicomheroObjcDicomDictionary__INCLUDED_
