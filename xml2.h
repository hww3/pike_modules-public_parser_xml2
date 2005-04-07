/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id: xml2.h,v 1.1 2005-04-07 19:00:41 hww3 Exp $
 */

/*
 * File licensing and authorship information block.
 *
 * Version: MPL 1.1/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Initial Developer of the Original Code is
 *
 * Bill Welliver <hww3@riverweb.com>
 *
 * Portions created by the Initial Developer are Copyright (C) Bill Welliver
 * All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of the LGPL, and not to allow others to use your version
 * of this file under the terms of the MPL, indicate your decision by
 * deleting the provisions above and replace them with the notice
 * and other provisions required by the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL or the LGPL.
 *
 * Significant Contributors to this file are:
 *
 *
 */

#define _GNU_SOURCE

#include "xml2_config.h"
#include "util.h"

#ifdef HAVE_XML2
#endif /* HAVE_XML2 */

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef HAVE_LIBXML_PARSER_H
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#endif

#ifdef HAVE_LIBXML_TREE_H
#include <libxml/tree.h>
#endif

#ifdef HAVE_LIBXML_SAX_H
#include <libxml/SAX2.h>
#endif

#ifdef HAVE_LIBXML_XPATH_H
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#endif

#define CB_INTERNALSUBSET 0
#define CB_ISSTANDALONE 1
#define CB_HASINTERNALSUBSET 2
#define CB_HASEXTERNALSUBSET 3
#define CB_RESOLVEENTITY 4
#define CB_GETENTITY 5
#define CB_ENTITYDECL 6
#define CB_NOTATIONDECL 7
#define CB_ATTRIBUTEDECL 8
#define CB_ELEMENTDECL 9
#define CB_UNPARSEDENTITYDECL 10
#define CB_SETDOCUMENTLOCATOR 11
#define CB_STARTDOCUMENT 12
#define CB_ENDDOCUMENT 13
#define CB_STARTELEMENT 14
#define CB_ENDELEMENT 15
#define CB_REFERENCE 16
#define CB_CHARACTERS 17
#define CB_IGNORABLEWHITESPACE 18
#define CB_PROCESSINGINSTRUCTION 19
#define CB_COMMENT 20
#define CB_WARNING 21
#define CB_ERROR 22
#define CB_FATALERROR 23
#define CB_GETPARAMETERENTITY 24
#define CB_CDATABLOCK 25
#define CB_EXTERNALSUBSET 26
#define CB_STARTELEMENTNS 27
#define CB_ENDELEMENTNS 28
#define CB_SERROR 29

struct program * Node_program;

extern ptrdiff_t Node_storage_offset;

  xmlParserInputPtr my_getParameterEntity(void * ctx, const xmlChar * name); 

  xmlParserInputPtr my_resolveEntity(void * ctx, const xmlChar * publicId, 
    const xmlChar * systemId);

  void my_startElementNs(void * ctx, const xmlChar * localname, 
    const xmlChar * prefix, const xmlChar * uri, 
    int nb_namespaces, const xmlChar ** namespaces,
    int nb_attributes, int nb_defaulted,
    const xmlChar ** atts);

  void my_endElementNs(void * ctx, const xmlChar * localname,
    const xmlChar * prefix, const xmlChar * uri);

  void my_serror(void * ctx, xmlErrorPtr error);
  void my_entityDecl(void * ctx, const xmlChar * name, int type, const xmlChar * publicId, const xmlChar * systemId, xmlChar * content);
  void my_unparsedEntityDecl(void * ctx, const xmlChar * name, const xmlChar * publicId, const xmlChar * systemId, const xmlChar * notationName);
  void my_attributeDecl(void * ctx, const xmlChar * elem, const xmlChar* fullname, int type, int def, const xmlChar * defaultValue, xmlEnumerationPtr tree);
  void my_elementDecl(void * ctx, const xmlChar * name, int type, xmlElementContentPtr content);
  void my_startElement(void * ctx, const xmlChar * fullname, const xmlChar ** atts);
  void my_comment(void * ctx, const xmlChar * name);
  void my_characters(void * ctx, const xmlChar * ch, int len);
  void my_cdataBlock(void * ctx, const xmlChar * ch, int len);
  void my_ignorableWhitespace(void * ctx, const xmlChar * ch, int len);
  void my_processingInstruction(void * ctx, const xmlChar * target, const xmlChar * data);
  void my_internalSubset(void * ctx, const xmlChar * name, const xmlChar * ExternalID, const xmlChar * SystemID);
  void my_externalSubset(void * ctx, const xmlChar * name, const xmlChar * ExternalID, const xmlChar * SystemID);
  void my_notationDecl(void * ctx, const xmlChar * name, const xmlChar * publicId, const xmlChar * systemId);
  void my_reference(void * ctx, const xmlChar * name);
  void my_endElement(void * ctx, const xmlChar * name);
  int my_hasInternalSubset(void * data);
  int my_hasExternalSubset(void * data);
  void my_startDocument(void * data);
  void my_endDocument(void * data);
  int my_isStandalone(void * data);
  void  make_PSAX_handler();
  struct array * get_callback_data(struct object * o);
  struct svalue * get_callback_func(struct object * o);



  typedef struct
  {
    xmlSAXHandlerPtr sax;
    struct array * handlers;
    xmlParserCtxtPtr context;
    xmlParserOption options;
  } SAX_OBJECT_DATA;

  typedef struct
  {
    xmlParserOption options;
  } PARSER_OBJECT_DATA;

  typedef struct
  {
    xmlNodePtr node;
    INT32 * refs;
  } NODE_OBJECT_DATA;

#ifndef THIS_IS_XML2_NODE

struct Node_struct {
 NODE_OBJECT_DATA   *object_data;
};

#endif

#define mySAX THIS->object_data->sax

#define MY_NODE (THIS->object_data->node)


#define OBJ2_NODE(o) ((struct Node_struct *)get_storage(o, Node_program))



#define NEW_NODE_OBJ(_X_, _Y_) { apply(Pike_fp->current_object, "Node", 0); \
  OBJ2_NODE((Pike_sp[0-1].u.object))->object_data->node = _Y_; \
  _X_ = Pike_sp[0-1].u.object; pop_stack(); }
#define NEW_NODE_OBJ_REFS(o)    OBJ2_NODE(o)->object_data->refs = THIS->object_data->refs; \
    (* OBJ2_NODE(o)->object_data->refs) ++;

#define NEW_NODE() clone_object(Node_program, 0)
#define NEW_NODE_REFS(o)  OBJ2_NODE(o)->object_data->refs = THIS->object_data->refs; \
      (* OBJ2_NODE(o)->object_data->refs)++; 

