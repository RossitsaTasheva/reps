//============================================================================
// Name        : Save_XML.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "pugixml.hpp"
using namespace std;


int main() {
	 pugi::xml_document doc;

	    // tag::code[]
	    // add node with some name
	    pugi::xml_node node = doc.append_child("node");

	    // add description node with text child
	    for(int i = 0; i<5;i++){
	    pugi::xml_node descr = node.append_child("description");
	    descr.append_child(pugi::node_pcdata).set_value("Simple node");

	    // add param node before the description
	    pugi::xml_node param = node.insert_child_before("param", descr);

	    // add attributes to param node
	    param.append_attribute("name") = "version";
	    param.append_attribute("value") = 1.1;
	    param.insert_attribute_after("type", param.attribute("name")) = "float";
	    // end::code[]
	    }
	    doc.print(std::cout);






	/*pugi::xml_document doc;
	doc.load_string("<students>"
				"<student id='11111'>"
					"<name>Joe Average</name>"
					"<age>21</age>"
					"<major>Biology</major>"
					" <address>"
						"<street>Ivan Asen</street>"
						"<city>Sofia</city>"
						"<country>Bulgaria</country>"
						"<zipCode>1547</zipCode>"
					"</address>"
					" <grades> "
						"<math>4</math>"
						" <BEL>6</BEL>"
						" <DTI>3</DTI>"
					"</grades>"
				"</student>"
				"<student id='22222'>"
					"<name>Jack Doe</name>"
					"<age>18</age>"
					"<major>Physics</major>"
					"<address>"
						"<street>Damareds</street>"
						"<city>Munster</city>"
						"<country>Germany</country>"
						"<zipCode>2356</zipCode>"
					"</address>"
					"<grades>"
						"<math>4</math>"
						"<BEL>6</BEL>"
						"<DTI>3</DTI>"
					"</grades>"
				"</student> ");

			cout << "Saving result: " <<
			doc.save_file("save_file_output.xml") << endl;
*/
			//----------------------------------------------------------------------------

			/*

			 // save to std
			 // get a test document
			 pugi::xml_document doc;
			 doc.load_string("<foo bar='baz'><call>hey</call></foo>");

			 // tag::code[]
			 // save document to standard output
			 cout << "Document:\n";
			 doc.save(cout);
			 // end::code[]
			 */

			return 0;
		}
