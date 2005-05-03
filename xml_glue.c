#include "util.h"
#include "module.h"

PIKE_MODULE_INIT
{
  pike_init_xml2_node();
  pike_init_xml2_constants();
  pike_init_xml2_sax();
  pike_init_xml2_stylesheet();
  pike_init_xml2_main();
}

PIKE_MODULE_EXIT
{
  pike_exit_xml2_constants();
  pike_exit_xml2_node();
  pike_exit_xml2_sax();
  pike_exit_xml2_stylesheet();
  pike_exit_xml2_main();
}
