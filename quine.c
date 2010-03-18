
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* s[] = {
  "",
  "#include <stdio.h>",
  "#include <stdlib.h>",
  "#include <string.h>",
  "",
  "const char* s[] = {",
  0,
  "};",
  "",
  "int main(int argc, char ** argv) {",
  "  int count = 0;",
  "  const char** line = s;",
  "  const char** cursor = s;",
  "",
  "  for (; *line; ++line)",
  "    printf(\"%s\\n\", *line);",
  "  ",
  "  while (count < 2) {",
  "    char* quoted = malloc(2 * strlen(*cursor));",
  "    char* q = quoted;",
  "    const char* c;",
  "    for (c = *cursor; *c; ++c) {",
  "      switch (*c) {",
  "        case '\\\\':",
  "          *q++ = '\\\\';",
  "          *q++ = '\\\\';",
  "          break;",
  "        case '\"':",
  "          *q++ = '\\\\';",
  "          *q++ = '\"';",
  "          break;",
  "        default:",
  "          *q++ = *c;",
  "      }",
  "    }",
  "    *q = '\\0';",
  "",
  "    printf(\"  \\\"%s\\\",\\n\", quoted);",
  "    free(quoted);",
  "    if (!*++cursor) {",
  "      if (!count)",
  "        printf(\"  0,\\n\");",
  "      ++cursor;",
  "      ++count;",
  "    }",
  "  }",
  "  printf(\"  0\\n\");",
  "",
  "  for (++line; *line; ++line)",
  "    printf(\"%s\\n\", *line);",
  "",
  "  return 0;",
  "}",
  "",
  0
};

int main(int argc, char ** argv) {
  int count = 0;
  const char** line = s;
  const char** cursor = s;

  for (; *line; ++line)
    printf("%s\n", *line);
  
  while (count < 2) {
    char* quoted = malloc(2 * strlen(*cursor));
    char* q = quoted;
    const char* c;
    for (c = *cursor; *c; ++c) {
      switch (*c) {
        case '\\':
          *q++ = '\\';
          *q++ = '\\';
          break;
        case '"':
          *q++ = '\\';
          *q++ = '"';
          break;
        default:
          *q++ = *c;
      }
    }
    *q = '\0';

    printf("  \"%s\",\n", quoted);
    free(quoted);
    if (!*++cursor) {
      if (!count)
        printf("  0,\n");
      ++cursor;
      ++count;
    }
  }
  printf("  0\n");

  for (++line; *line; ++line)
    printf("%s\n", *line);

  return 0;
}

