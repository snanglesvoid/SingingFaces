/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== test.xml ==================
static const unsigned char temp_binary_data_0[] =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
"\r\n"
"<element name=\"root\">\r\n"
"  <rectangle name=\"background\" borderColor=\"ff008020\" fillColor=\"ff005010\" x=\"0\" y=\"0\" width=\"1\" height=\"1\" borderWidth=\"10\">\r\n"
"    <spline name=\"spline\" color=\"8899aa33\" lineThickness=\"2\" precision=\"50\">\r\n"
"      <points>\r\n"
"        <point x=\"0.5\" y=\"0.1\"/>\r\n"
"        <point x=\"0.2\" y=\"0.2\"/>\r\n"
"        <point x=\"0.3\" y=\"0.3\"/>\r\n"
"        <point x=\"0.4\" y=\"0.5\"/>\r\n"
"        <point x=\"0.1\" y=\"0.2\"/>\r\n"
"        <point x=\"0.7\" y=\"0.3\"/>\r\n"
"      </points>\r\n"
"    </spline>\r\n"
"    <rectangle name=\"rectangle\" fillColor=\"88ffffff\" borderColor=\"ffffffff\" x=\"0.2\" y=\"0.2\" width=\"0.3\" height=\"0.6\" clip=\"true\" radius=\"20\">\r\n"
"      <ellipse name=\"ellipse\" fillColor=\"88111144\" borderColor=\"ff111144\" x=\"0.2\" y=\"0.3\" width=\"0.2\" height=\"0.4\"/>\r\n"
"      <text name=\"text\" color=\"ff000000\" text=\"hello world\" x=\"0.25\" y=\"0.4\" width=\"0.2\" height=\"0.05\"/>\r\n"
"    </rectangle>\r\n"
"    <polygon name=\"pentagon\" borderColor=\"ff881111\" fillColor=\"88881111\" borderWidth=\"2\" radius=\"0\">\r\n"
"      <points>\r\n"
"        <point x=\"0.5\" y=\"0.2\"/>\r\n"
"        <point x=\"0.7\" y=\"0.3\"/>\r\n"
"        <point x=\"0.6\" y=\"0.4\"/>\r\n"
"        <point x=\"0.4\" y=\"0.4\"/>\r\n"
"        <point x=\"0.3\" y=\"0.3\"/>\r\n"
"      </points>\r\n"
"    </polygon>\r\n"
"  </rectangle>\r\n"
"</element>";

const char* test_xml = (const char*) temp_binary_data_0;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xbbaaaaea:  numBytes = 1254; return test_xml;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "test_xml"
};

}
