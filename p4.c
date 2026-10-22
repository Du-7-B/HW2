#include <stdio.h>

int main(int argc, char *argv[])
{
    /* TODO: your code here */
    (void)argc;
    (void)argv;
    int i = 1;
    while (i < argc)
    {
        const char *a = argv[i];
        const char *b = "-o";
        int eq_o = 1;
        while (*a && *b)
        {
            if (*a != *b)
            {
                eq_o = 0;
                break;
            }
            a++;
            b++;
        }
        if (eq_o && (*a == *b))
        {
            if (i + 1 >= argc) break;
            i++;
            printf("-o %s: Place the primary output in file %s.\n", argv[i], argv[i]);
            i++;
            continue;
        }

        a = argv[i];
        b = "-I";
        int eq_I = 1;
        while (*a && *b)
        {
            if (*a != *b)
            {
                eq_I = 0;
                break;
            }
            a++;
            b++;
        }
        if (eq_I && (*a == *b))
        {
            if (i + 1 >= argc) break;
            i++;
            printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", argv[i], argv[i]);
            i++;
            continue;
        }

        a = argv[i];
        b = "-Wall";
        int eq_wall = 1;
        while (*a && *b)
        {
            if (*a != *b)
            {
                eq_wall = 0;
                break;
            }
            a++;
            b++;
        }
        if (eq_wall && (*a == *b))
        {
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
            i++;
            continue;
        }

        a = argv[i];
        b = "-Wpedantic";
        int eq_ped = 1;
        while (*a && *b)
        {
            if (*a != *b)
            {
                eq_ped = 0;
                break;
            }
            a++;
            b++;
        }
        if (eq_ped && (*a == *b))
        {
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
            i++;
            continue;
        }

        a = argv[i];
        b = "-Wextra";
        int eq_extra = 1;
        while (*a && *b)
        {
            if (*a != *b)
            {
                eq_extra = 0;
                break;
            }
            a++;
            b++;
        }
        if (eq_extra && (*a == *b))
        {
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
            i++;
            continue;
        }

        a = argv[i];
        b = "-Werror";
        int eq_error = 1;
        while (*a && *b)
        {
            if (*a != *b)
            {
                eq_error = 0;
                break;
            }
            a++;
            b++;
        }
        if (eq_error && (*a == *b))
        {
            printf("-Werror: Make all warnings into errors.\n");
            i++;
            continue;
        }

        /* ---- -std= 分支：gnu++ / gnu / c++ / 纯c 依次判断 ---- */
        const char *s = argv[i];
        const char *p = "-std=";
        int ps = 1;
        while (*p)
        {
            if (*s != *p)
            {
                ps = 0;
                break;
            }
            s++;
            p++;
        }
        if (ps)
        {
            int gnu = 0;
            int cpps = 0;
            const char *t;
            int m;

            /* 1) gnu++ 必须最先匹配，否则会被 gnu 抢走前缀 */
            t = s;
            {
                const char *tg = "gnu++";
                m = 1;
                while (*tg)
                {
                    if (*t != *tg) { m = 0; break; }
                    t++;
                    tg++;
                }
                if (m) { gnu = 1; cpps = 1; s = t; }
            }

            /* 2) gnu（不带 ++） */
            if (!gnu)
            {
                t = s;
                const char *tg = "gnu";
                m = 1;
                while (*tg)
                {
                    if (*t != *tg) { m = 0; break; }
                    t++;
                    tg++;
                }
                if (m) { gnu = 1; s = t; }
            }

            /* 3) c++ */
            if (!cpps)
            {
                t = s;
                const char *tc = "c++";
                m = 1;
                while (*tc)
                {
                    if (*t != *tc) { m = 0; break; }
                    t++;
                    tc++;
                }
                if (m) { cpps = 1; s = t; }
            }

            /* 4) 只有纯 ISO C（形如 c17）才需要跳过开头的 c */
            if (!gnu && !cpps)
            {
                s++;
            }

            printf("%s: Set the language standard to ", argv[i]);
            if (gnu)
                printf("GNU dialect of ");
            else
                printf("ISO ");
            if (cpps)
                printf("C++%s.\n", s);
            else
                printf("C%s.\n", s);
            i++;
            continue;
        }

        /* ---- 剩下的当文件名，提取最后一个 '.' 之后的扩展名 ---- */
        const char *ext = "";
        const char *q;
        for (q = argv[i]; *q; q++)
        {
            if (*q == '.')
            {
                ext = q + 1;
            }
        }

        a = ext;
        b = "c";
        int eq_c = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_c = 0; break; }
            a++; b++;
        }
        if (eq_c && (*a == *b))
        {
            printf("%s: C source code as input file.\n", argv[i]);
            i++;
            continue;
        }

        a = ext;
        b = "h";
        int eq_h = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_h = 0; break; }
            a++; b++;
        }
        if (eq_h && (*a == *b))
        {
            printf("%s: C/C++ header file as input file.\n", argv[i]);
            i++;
            continue;
        }

        a = ext;
        b = "cpp";
        int eq_cpp = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_cpp = 0; break; }
            a++; b++;
        }
        if (eq_cpp && (*a == *b))
        {
            printf("%s: C++ source code as input file.\n", argv[i]);
            i++;
            continue;
        }

        a = ext;
        b = "C";
        int eq_C = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_C = 0; break; }
            a++; b++;
        }
        if (eq_C && (*a == *b))
        {
            printf("%s: C++ source code as input file.\n", argv[i]);
            i++;
            continue;
        }

        a = ext;
        b = "cc";
        int eq_cc = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_cc = 0; break; }
            a++; b++;
        }
        if (eq_cc && (*a == *b))
        {
            printf("%s: C++ source code as input file.\n", argv[i]);
            i++;
            continue;
        }

        a = ext;
        b = "cxx";
        int eq_cxx = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_cxx = 0; break; }
            a++; b++;
        }
        if (eq_cxx && (*a == *b))
        {
            printf("%s: C++ source code as input file.\n", argv[i]);
            i++;
            continue;
        }

        a = ext;
        b = "hpp";
        int eq_hpp = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_hpp = 0; break; }
            a++; b++;
        }
        if (eq_hpp && (*a == *b))
        {
            printf("%s: C++ header file as input file.\n", argv[i]);
            i++;
            continue;
        }

        a = ext;
        b = "hxx";
        int eq_hxx = 1;
        while (*a && *b)
        {
            if (*a != *b) { eq_hxx = 0; break; }
            a++; b++;
        }
        if (eq_hxx && (*a == *b))
        {
            printf("%s: C++ header file as input file.\n", argv[i]);
            i++;
            continue;
        }

        printf("%s: unknown as input file.\n", argv[i]);
        i++;
    }
    return 0;
}
