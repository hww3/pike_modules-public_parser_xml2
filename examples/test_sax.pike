//
// test the SAX2 compliant parser.
//

import .module.Constants;

 void serror_cb(mapping(string:mixed) error)
{
   werror("serror: %O\n", error);
// mapping elements: domain, code, message, level, line, column
}

 void entitydecl_cb(string name, int type, string publicId, string systemId, string content, mixed ... extra_args)
{
   werror("entitydecl: %O %O %O %O %O %O\n", name, type, publicId, systemId, content, extra_args);
}

 void elementdecl_cb(string name, int type, mixed ... extra_args)
{
   werror("elementdecl: %O %O %O\n", name, type,  extra_args);
}

 void unparsedentitydecl_cb(string name, string publicId, string systemId, string notationName, mixed ... extra_args)
{
   werror("unparsedentitydecl: %O %O %O %O %O\n", name, publicId, systemId, notationName, extra_args);
}

 void attributedecl_cb(string elem, string fullname, int type, int def, string defaultValue, mixed ... extra_args)
{
   werror("attributedecl: %O %O %O %O %O\n", fullname, type, def, defaultValue, extra_args);
}

 void notationdecl_cb(string name, string publicId, string systemId, mixed ... extra_args)
{
   werror("notationdecl: %O %O %O %O\n", name, publicId, systemId, extra_args); 
}

 void internalsubset_cb(string name, string ExternalId, string SystemId, mixed ... extra_args)
{
   werror("internalsubset: %O %O %O %O\n", name, ExternalId, SystemId, extra_args); 
}

 void externalsubset_cb(string name, string ExternalId, string SystemId, mixed ... extra_args)
{
   werror("externalsubset: %O %O %O %O\n", name, ExternalId, SystemId, extra_args); 
}

 void processinginstruction_cb(string target, string data, mixed ... extra_args)
{
   werror("processinginstruction: %O %O %O\n", target, data, extra_args); 
}

 void endelement_cb(string name, mixed ... extra_args)
{
   werror("endelement: %O %O\n", name, extra_args); 
}

string resolveentity_cb(string publicId, string systemId, mixed ... 
extra_args)
{
  werror("resolveentity: %s, %s, %O\n", publicId, systemId, extra_args);
  return "wahoo!";
}

 void endelementns_cb(string name, string prefix, string uri, mixed ... 
extra_args)
{
   werror("endelement: %s, %s, %s %O\n", name, (string)prefix, 
(string)uri, extra_args); 
}

 void misc_cb(mixed ... extra_args)
{
   werror("misc: %O\n",extra_args); 
//exit(1);
}

 void comment_cb(string name, mixed ... extra_args)
{
   werror("comment: %O %O\n", name, extra_args); 
}

 void cdatablock_cb(string chars, mixed ... extra_args);

 void ignorablewhitespace(string chars, mixed ... extra_args);

 void characters_cb(string chars, mixed ... extra_args);

 void reference_cb(string name, mixed ... extra_args)
{
  werror("reference: \n", name); 
}

 void comment_cb(string value, mixed ... extra_args);

 void startelement_cb(string name, mapping(string:string) attributes, mixed ... extra_args);

 int isstandalone_cb(mixed ... extra_args)
 {
    werror("is standalone\n");
    return 1;
 }

 void startdocument_cb(mixed ... extra_args)
 {
    werror("startdocument\n");
  }

 void enddocument_cb(mixed ... extra_args)
 {
    werror("enddocument\n");
  }

 int hasinternalsubset(mixed ... extra_args);

 int hasexternalsubset(mixed ... extra_args);


int main()
{
//  string s = 
//Protocols.HTTP.get_url_data("http://hww3.riverweb.com/exec/rss?snip=start");

string s  = Stdio.read_file("/tmp/xmldaat");
//
do
  {
     object sax = module.SAX();
     sax->set_callback(SAX_CB_SERROR, serror_cb);
//     sax->set_callback(SAX_CB_ENTITYDECL, entitydecl_cb);
//     sax->set_callback(SAX_CB_ENDELEMENT, endelement_cb);
     sax->set_callback(SAX_CB_ELEMENTDECL, elementdecl_cb);
     sax->set_callback(SAX_CB_ATTRIBUTEDECL, attributedecl_cb);
     sax->set_callback(SAX_CB_NOTATIONDECL, notationdecl_cb);
     sax->set_callback(SAX_CB_UNPARSEDENTITYDECL, unparsedentitydecl_cb);
     sax->set_callback(SAX_CB_INTERNALSUBSET, internalsubset_cb);
     sax->set_callback(SAX_CB_ENDDOCUMENT, enddocument_cb);
     sax->set_callback(SAX_CB_STARTDOCUMENT, startdocument_cb);
//     sax->set_callback(SAX_CB_ENDELEMENTNS, endelementns_cb, "blah"); 
//     sax->set_callback(SAX_CB_STARTELEMENTNS, misc_cb); 
//     sax->set_callback(SAX_CB_COMMENT, comment_cb);
     sax->set_callback(SAX_CB_REFERENCE, reference_cb);
     sax->set_callback(SAX_CB_ISSTANDALONE, isstandalone_cb);
/**/
     sax->set_callback(SAX_CB_RESOLVEENTITY, resolveentity_cb);
     sax->set_callback(SAX_CB_PROCESSINGINSTRUCTION, processinginstruction_cb);
     sax->parse(s);
//werror("parsed!\n");
//     sax = 0;
  } 
while(0);

  return 0;
}
