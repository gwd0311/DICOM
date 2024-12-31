/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcTcpStream__INCLUDED_)
#define dicomheroObjcTcpStream__INCLUDED_

#import <Foundation/Foundation.h>

#include "dicomhero_macros.h"

@class DicomheroTCPActiveAddress;
@class DicomheroTCPAddress;
@class DicomheroBaseStreamInput;
@class DicomheroBaseStreamOutput;


///
/// \brief Represents a TCP stream.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroTCPStream: NSObject

{
    @public
    define_dicomhero_object_holder(TCPStream);
}

    -(id)initWithDicomheroTcpStream:define_dicomhero_parameter(TCPStream);

    -(void)dealloc;

    ///
    /// \brief Construct a TCP socket and connects it to the destination address.
    ///
    /// This is a non-blocking operation (the connection proceed after the
    /// constructor returns). Connection errors will be reported later while
    /// the communication happens.
    ///
    /// \param pAddress the address to which the socket has to be connected.
    /// \param pError   set to a StreamError derived class in case of error
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithAddress:(DicomheroTCPActiveAddress*)pAddress error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

    ///
    /// \brief Returns the address of the connected peer.
    ///
    /// \param pError   set to a StreamError derived class in case of error
    /// \return the address of the connected peer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroTCPAddress*) getPeerAddress: (NSError**)pError DICOMHERO_NONNULL_ERROR;

    ///
    /// \brief Return a DicomheroBaseStreamInput object able to read from the TCP
    ///        Stream.
    ///
    /// \return a DicomheroBaseStreamInput object able to read from the TCPStream.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroBaseStreamInput*) getStreamInput;

    ///
    /// \brief Return a DicomheroBaseStreamOutput object able to write into the TCP
    ///        Stream.
    ///
    /// \return a DicomheroBaseStreamOutput object able to write into the
    ///         TCPStream.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroBaseStreamOutput*) getStreamOutput;

@end


#endif // dicomheroObjcTcpStream__INCLUDED_
