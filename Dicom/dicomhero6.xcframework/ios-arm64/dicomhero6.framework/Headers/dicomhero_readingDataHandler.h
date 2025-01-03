/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcReadingDataHandler__INCLUDED_)
#define dicomheroObjcReadingDataHandler__INCLUDED_

#import <Foundation/Foundation.h>
#include "dicomhero_macros.h"

@class DicomheroDate;
@class DicomheroAge;
@class DicomheroPersonName;

///
/// \brief DicomheroReadingDataHandler allows reading the content of a Dicom
///        Tag.
///
/// DicomheroReadingDataHandler is able to return the Tag's content as a string,
/// a number, a date/time or an age.
///
/// In order to obtain a DicomheroReadingDataHandler object for a specific
/// DicomheroTag stored in a DicomheroDataSet, call
/// DicomheroDataSet::getReadingDataHandler() or
/// DicomheroTag::getReadingDataHandler().
///
/// DicomheroReadingDataHandler keeps a reference to the buffer's memory:
/// the buffer's memory is never modified but only replaced by a new memory
/// area, therefore the ReadingDataHandler client does not need to worry about
/// other clients modifying the memory being read.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroReadingDataHandler: NSObject

{
    @public
    define_dicomhero_object_holder(ReadingDataHandler);
}

    -(id)initWithDicomheroReadingDataHandler:define_dicomhero_parameter(ReadingDataHandler);

    -(void)dealloc;

    /// \brief Returns the number of elements in the tag's buffer handled by the
    ///        data handler.
    ///
    /// If the DicomheroReadingDataHandler object is related to a buffer that contains
    /// strings then it returns the number of strings stored in the buffer.
    /// Multiple strings are separated by a separator char.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) unsigned int size;

    /// \brief Retrieve a buffer's value as signed very long integer (64 bit).
    ///
    /// If the buffer's value cannot be converted to a signed very long integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a signed 364 bit integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(signed long long) getInt64:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as signed 32 bits integer.
    ///
    /// If the buffer's value cannot be converted to a signed 32 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a signed 32 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(signed int) getInt32:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Deprecated. Use getInt32() instead.
    ///
    /// If the buffer's value cannot be converted to a signed 32 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a signed 32 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(signed int) getSignedLong:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as signed 16 bits integer.
    ///
    /// If the buffer's value cannot be converted to a signed 16 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a signed 16 bit integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(signed short) getInt16:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as signed 8 bits integer.
    ///
    /// If the buffer's value cannot be converted to a signed 8 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a signed 8 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(signed char) getInt8:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as an unsigned 64 bits integer.
    ///
    /// If the buffer's value cannot be converted to a unsigned 64 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as an unsigned 64 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(unsigned long long) getUint64:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as an unsigned 32 bits integer.
    ///
    /// When calling getUint32() on an AT tag (Attribute Tag) then the tag group
    /// is always in the high word of the returned value.
    ///
    /// If the buffer's value cannot be converted to a unsigned 32 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as an unsigned 32 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(unsigned int) getUint32:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Deprecated. Use getUint32() instead.
    ///
    /// When calling getUint32() on an AT tag (Attribute Tag) then the tag group
    /// is always in the high word of the returned value.
    ///
    /// If the buffer's value cannot be converted to a unsigned 32 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as an unsigned 32 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(unsigned int) getUnsignedLong:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as an unsigned 16 bits integer.
    ///
    /// If the buffer's value cannot be converted to a unsigned 16 bits integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as an unsigned 16 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(unsigned short) getUint16:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as an unsigned 8 bits integer.
    ///
    /// If the buffer's value cannot be converted to a unsigned long integer
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as an unsigned 8 bits integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(unsigned char) getUint8:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as a double floating point value (64 bit).
    ///
    /// If the buffer's value cannot be converted to a double floating point
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a double floating point value (64 bit)
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(double) getDouble:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as a floating point value (32 bit).
    ///
    /// If the buffer's value cannot be converted to a double floating point
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a floating point value (32 bit)
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(float) getFloat:(unsigned int)index error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as a string.
    ///
    /// If the buffer's value cannot be converted to a string
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a string
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(NSString*) getString:(unsigned int)index error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as date or time.
    ///
    /// If the buffer's value cannot be converted to a date or time
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a date or time
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroDate*) getDate:(unsigned int)index error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as person name.
    ///
    /// If the buffer's value cannot be converted to a person name
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as a date or time
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroPersonName*) getPersonName:(unsigned int)index error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    /// \brief Retrieve a buffer's value as an age.
    ///
    /// If the buffer's value cannot be converted to an age
    /// then set pError to DicomheroDataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param pError set to a NSError derived class in case of error
    /// \return the tag's value as an Age
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroAge*) getAge:(unsigned int)index error:(NSError**)pError DICOMHERO_NONNULL_ERROR;


@end

#endif // !defined(dicomheroObjcReadingDataHandler__INCLUDED_)
