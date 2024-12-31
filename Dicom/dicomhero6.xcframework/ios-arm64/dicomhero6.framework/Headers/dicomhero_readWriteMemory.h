/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcReadWriteMemory__INCLUDED_)
#define dicomheroObjcReadWriteMemory__INCLUDED_

#import "dicomhero_readMemory.h"
#import <Foundation/Foundation.h>

///
/// \brief Manages a writable buffer of memory.
///
/// The buffer of memory is usually associated with a tag buffer content.
///
/// The memory used by DicomheroReadMemory and DicomheroMutableMemory is managed
/// by DicomheroMemoryPool.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroMutableMemory: DicomheroMemory

    -(id)initWithDicomheroMutableMemory:define_dicomhero_parameter(MutableMemory);

    /// \brief Construct an empty buffer of memory.
    ///
    /// The memory can be resized later with resize().
    ///
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)init;

    /// \brief Construct a buffer of memory of the specified size.
    ///
    /// The memory can be resized later with resize().
    ///
    /// \param size the initial memory's size, in bytes
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithSize:(unsigned int)size;

    /// \brief Construct a buffer of memory and copy the specified content into it.
    ///
    /// \param source the object containing the initial memory's content
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithMemory:(DicomheroMemory*)source;

    /// \brief Construct a buffer of memory and copy the specified content into it.
    ///
    /// \param pSource the object containing the initial memory's content
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithData:(NSData*)pSource;

    /// \brief Copy the content from another memory object.
    ///
    /// \param source the source memory object
    /// \param pError set to a NSError derived class in case of error
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void)copyFrom:(DicomheroMemory*)source error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Resize the memory to zero bytes.
    ///
    /// \param pError set to a NSError derived class in case of error
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void)clear:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Resize the memory.
    ///
    /// \param newSize the new memory size, in bytes
    /// \param pError  set to a NSError derived class in case of error
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void)resize:(unsigned int)newSize error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Reserve the specified amount of bytes, without changing the memory
    ///        size
    ///
    /// \param reserveSize the number of bytes to reserve
    /// \param pError      set to a NSError derived class in case of error
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void)reserve:(unsigned int)reserveSize error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Copy the content of the specified buffer into the ReadWriteMemory
    ///        object.
    ///
    /// \param pSource     a pointer to the source memory buffer
    /// \param pError      set to a NSError derived class in case of error
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void)assign:(NSData*)pSource error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

    /// \brief Copy the content of the specified buffer into a region of the
    ///        ReadWriteMemory.
    ///
    /// The memory size remains unchanged.
    ///
    /// \param pSource           a pointer to the source memory buffer
    /// \param destinationOffset the offset into the ReadWriteMemory at which the
    ///                          data must be copied
    /// \param pError            set to a NSError derived class in case of error
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(void)assignRegion:(NSData*)pSource offset:(unsigned int)destinationOffset error:(NSError**)pError
        DICOMHERO_NONNULL_ERROR;

@end

#endif // !defined(dicomheroObjcReadWriteMemory__INCLUDED_)
