$NetBSD$

--- jdk/test/sun/security/ec/TestEC.java.orig	2013-02-20 17:07:30.000000000 +0000
+++ jdk/test/sun/security/ec/TestEC.java
@@ -82,7 +82,7 @@ public class TestEC {
         // ClientJSSEServerJSSE fails on Solaris 11 when both SunEC and
         // SunPKCS11-Solaris providers are enabled.
         // Workaround:
-        // Security.removeProvider("SunPKCS11-Solaris");
+        Security.removeProvider("SunPKCS11-Solaris");
         new ClientJSSEServerJSSE().main(p);
 
         long stop = System.currentTimeMillis();
