/* Copyright (c) 2010 Kenneth Waters
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* Simple yet verbose C quine. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* s[] = {
  "/* Copyright (c) 2010 Kenneth Waters",
  " * ",
  " * Permission is hereby granted, free of charge, to any person obtaining a copy",
  " * of this software and associated documentation files (the \"Software\"), to deal",
  " * in the Software without restriction, including without limitation the rights",
  " * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell",
  " * copies of the Software, and to permit persons to whom the Software is",
  " * furnished to do so, subject to the following conditions:",
  " * ",
  " * The above copyright notice and this permission notice shall be included in",
  " * all copies or substantial portions of the Software.",
  " * ",
  " * THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR",
  " * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,",
  " * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE",
  " * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER",
  " * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,",
  " * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN",
  " * THE SOFTWARE.",
  " */",
  "",
  "/* Simple yet verbose C quine. */",
  "",
  "#include <stdio.h>",
  "#include <stdlib.h>",
  "#include <string.h>",
  "",
  "const char* s[] = {",
  0,
  "};",
  "",
  "int main(int argc, char** argv) {",
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

int main(int argc, char** argv) {
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

