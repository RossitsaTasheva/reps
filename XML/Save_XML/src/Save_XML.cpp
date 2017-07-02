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

void XMLsave_file() {
	pugi::xml_document doc;
	doc.load_string("<foo bar='baz'><call>hey</call></foo>");
	doc.load_string("<foo bar='baz'><call>hey</call></foo>");
	doc.load_string("<foo bar='baz'><call>hey</call></foo>");
	doc.load_string("<foo bar='baz'><call>hey</call></foo>");

	cout << "Saving result: " << doc.save_file("save_file_output.xml") << endl;

}

int main() {
	pugi::xml_document doc;
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
