/*
Copyright 2005 - 2021 by Paolo Brandoli/Binarno s.p.

DICOMHero/Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for DICOMHero/Imebra from the DICOMHero’s website (https://dicomhero.com).
*/

#if !defined(imebraMacros__INCLUDED_)
#define imebraMacros__INCLUDED_

#define define_dicomhero_object_holder(Type) void* m_##Type
#define define_dicomhero_parameter(Type) (void*)parameter_##Type

#ifdef __APPLE__
    #define DICOMHERO_NONNULL_ERROR  __attribute__((swift_error(nonnull_error)))
#else
    #define DICOMHERO_NONNULL_ERROR
#endif


#endif // imebraMacros__INCLUDED_
