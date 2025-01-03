/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#import "dicomhero_readingDataHandler.h"
#import <Foundation/Foundation.h>

#if !defined(dicomheroObjcReadingDataHandlerNumeric__INCLUDED_)
#define dicomheroObjcReadingDataHandlerNumeric__INCLUDED_

@class DicomheroWritingDataHandlerNumeric;
@class DicomheroMemory;

///
/// \brief Specialized dicomheroReadingDataHandler for numeric data types.
///
/// Includes few methods that allow accessing the raw memory containing the
/// buffer's data.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroReadingDataHandlerNumeric: DicomheroReadingDataHandler

    /// \brief Return a ReadMemory object referencing the raw buffer's data.
    ///
    /// \param pError set to a NSError derived class in case of error
    /// \return a ReadMemory object referencing the raw buffer's data
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroMemory*)getMemory: (NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Copies the content of the data handler into another data handler,
    ///        converting the data to the destination handler data type.
    ///
    /// \warning the size of the destination data handler stays unchanged: if
    ///          the destination too small to contain all the data to be copied
    ///          then only a part of the data will be copied.
    ///
    /// \param pError      set to a NSError derived class in case of error
    /// \param destination the destination data handler
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void)copyTo:(DicomheroWritingDataHandlerNumeric*)destination error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Returns the number of bytes occupied by the numbers handled by the
    ///        data handler
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) unsigned int unitSize;

    /// \brief Returns true if the numbers stored in the buffer are signed, false
    ///        otherwise.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) bool isSigned;

    /// \brief Returns true if the numbers stored in the buffer are floating point
    ///        numbers, false otherwise.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) bool isFloat;


@end

#endif // !defined(dicomheroObjcReadingDataHandlerNumeric__INCLUDED_)
