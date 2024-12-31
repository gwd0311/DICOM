/*
Copyright 2005 - 2023 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(dicomheroObjcXML__INCLUDED_)
#define dicomheroObjcXML__INCLUDED_

#import <Foundation/Foundation.h>
#include "dicomhero_macros.h"

@class DicomheroDataSet;
@class DicomheroXMLDOMAttribute;
@class DicomheroXMLDOMNode;


///
/// \brief An XML DOM attribute.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroXMLDOMAttribute: NSObject
{
    @public
    define_dicomhero_object_holder(XMLDOMAttribute);
}

    ///
    /// \brief Initializes the attribute with a string value.
    ///
    /// \param value     the string value to store into the attribute
    /// \param nameSpace the attribute's namespace
    /// \param name      the attribute's name
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithString:(NSString*)value nameSpace:(NSString*)nameSpace name:(NSString*)name;

    ///
    /// \brief Initializes the attribute with an integer value.
    ///
    /// \param value     the integer value to store into the attribute
    /// \param nameSpace the attribute's namespace
    /// \param name      the attribute's name
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithInteger:(int)value nameSpace:(NSString*)nameSpace name:(NSString*)name;

    -(id)initWithDicomheroXMLDOMAttribute:define_dicomhero_parameter(XMLDOMAttribute);

    -(void)dealloc;

    ///
    /// \brief Returns the attribute's namespace.
    /// \return the attribute's namespace
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* nameSpace;

    ///
    /// \brief Returns the attribute's name.
    /// \return the attribute's name
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* name;

    ///
    /// \brief Returns the attribute's value as a string.
    /// \return the attribute's value as a string
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* stringValue;

    ///
    /// \brief Returns the attribute's value as an integer.
    /// \return the attribute's value as an integer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) long integerValue;

@end


///
/// \enum DicomheroXMLDOMValueType
/// \brief The data type of the value stored in a DicomheroXMLDOMNode.
///
///////////////////////////////////////////////////////////////////////////////
typedef NS_ENUM(int, DicomheroXMLDOMValueType)
{
    DicomheroXMLDOMValueTypeString = 0, ///< The value stored in the DicomheroXMLDOMNode is a string.
    DicomheroXMLDOMValueTypeBinary = 1  ///< The value stored in the DicomheroXMLDOMNode is a binary string.
};


///
/// \brief A single XML DOM node.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroXMLDOMNode: NSObject
{
    @public
    define_dicomhero_object_holder(XMLDOMNode);
}

    ///
    /// \brief Initializes the node with a string value.
    ///
    /// \param value     the string value to store into the node
    /// \param nameSpace the node's namespace
    /// \param name      the node's name
    /// \return the object's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithString:(NSString*)value nameSpace:(NSString*)nameSpace name:(NSString*)name;

    ///
    /// \brief Initializes the node with a binary value.
    ///
    /// \param value     the binary value to store into the node
    /// \param nameSpace the node's namespace
    /// \param name      the node's name
    /// \return the obkect's ID
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(id)initWithBinary:(NSData*)value nameSpace:(NSString*)nameSpace name:(NSString*)name;
    -(id)initWithDicomheroXMLDOMNode:define_dicomhero_parameter(XMLDOMNode);

    -(void)dealloc;

    ///
    /// \brief Adds an attribute to the node.
    ///
    /// \param  attribute the attribute to add to the node
    /// \return the current node
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroXMLDOMNode*)addAttribute:(DicomheroXMLDOMAttribute*)attribute;

    ///
    /// \brief Adds a child node.
    ///
    /// \param node the child node to add to the node
    /// \return     the current node
    ///
    ///////////////////////////////////////////////////////////////////////////////
    -(DicomheroXMLDOMNode*)addNode:(DicomheroXMLDOMNode*)node;

    ///
    /// \brief Returns the node's namespace.
    /// \return the node's namespace
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* nameSpace;

    ///
    /// \brief Returns the node's name.
    /// \return the node's name
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSString* name;

    ///
    /// \brief Returns the type of the node's value.
    /// \return the type of the node's value
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) DicomheroXMLDOMValueType valueType;

    ///
    /// \brief The node's value (when the type is a string).
    /// \return the node's value as a string
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property NSString* stringValue;

    ///
    /// \brief The node's value (when the type is binary).
    /// \warning Binary data should be encoded in base64 format when written
    ///          to the XML file
    /// \return the node's value as an array of binary data
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property NSData* binaryValue;

    ///
    /// \brief Returns the node's attributes.
    /// \return the node's attributes as a dictionary (the attribute's name is the
    ///         key, the DicomheroXMLDOMAttribute is the object)
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSDictionary* attributes;

    ///
    /// \brief Returns the node's children.
    /// \return the node's attributes as an array of DicomheroXMLDOMNode objects
    ///
    ///////////////////////////////////////////////////////////////////////////////
    @property (readonly) NSArray* nodes;

@end


///
/// \brief XML DOM generator. Takes a DicomheroDataSet as input and generates
///        a list of DicomheroXMLDOMNode objects.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroXMLDOMGenerator: NSObject

    ///
    /// \brief Takes a DicomheroDataSet as input and generates a
    ///        DicomheroXMLDOMNode object.
    ///
    /// \param dataSet the DicomheroDataSet object to convert to XML DOM
    /// \return an DicomheroXMLDOMNode object representing the XML
    ///         structure
    ///////////////////////////////////////////////////////////////////////////////
    +(DicomheroXMLDOMNode*)generate:(DicomheroDataSet*)dataSet;

@end


///
/// \brief XML DOM parser. Takes a list of DicomheroXMLDOMNode objects and
///        generates a DicomheroDataSet.
///
///////////////////////////////////////////////////////////////////////////////
@interface DicomheroXMLDOMParser: NSObject

    ///
    /// \brief Takes a list of DicomheroXMLDOMNode objects and generates a
    ///        DicomheroDataSet object.
    ///
    /// \param xmlNode a DicomheroXMLDOMNode object generated by parsing an XML
    ///                file
    /// \param pError  set to a NSError derived class in case of error
    /// \return a DicomheroDataSet object
    ///
    ///////////////////////////////////////////////////////////////////////////////
    +(DicomheroDataSet*)parse:(DicomheroXMLDOMNode*)xmlNode error:(NSError**)pError DICOMHERO_NONNULL_ERROR;

@end

#endif // dicomheroObjcXML__INCLUDED_
