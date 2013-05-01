$NetBSD$

Avoid libdemangle with GCC.

--- hotspot/src/os/solaris/vm/decoder_solaris.cpp.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/src/os/solaris/vm/decoder_solaris.cpp
@@ -27,6 +27,11 @@
 #include <demangle.h>
 
 bool ElfDecoder::demangle(const char* symbol, char *buf, int buflen) {
+#ifdef SPARC_WORKS
   return !cplus_demangle(symbol, buf, (size_t)buflen);
+#else
+  memcpy(buf, symbol, (size_t)buflen);
+  return 0;
+#endif
 }
 
