#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <stdlib.h>
#include "../include/xml_reader.h"

int parse_prices_from_xml(const char *filename, float *output, int max_prices) {
    xmlDocPtr doc = xmlReadFile(filename, NULL, 0);
    fprintf(stderr, "Parsing XML file: %s\n", filename);
    if (doc == NULL) {
        fprintf(stderr, "Error: could not parse file %s\n", filename);
        return -1;
    }
    if (doc == NULL) return -1;

    xmlNode *root = xmlDocGetRootElement(doc);
    int count = 0;

    for (xmlNode *cur = root->children; cur && count == 0; cur = cur->next) {
        if (cur->type == XML_ELEMENT_NODE && strcmp((char *)cur->name, "testCase") == 0) {
            for (xmlNode *child = cur->children; child; child = child->next) {
                if (child->type == XML_ELEMENT_NODE && strcmp((char *)child->name, "prices") == 0) {
                    char *content = (char *)xmlNodeGetContent(child);
                    char *token = strtok(content, ",");
                    while (token && count < max_prices) {
                        output[count++] = atof(token);
                        token = strtok(NULL, ",");
                    }
                    xmlFree(content);
                }
            }
        }
    }

    xmlFreeDoc(doc);
    xmlCleanupParser();
    return count;
}
