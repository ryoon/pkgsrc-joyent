# $NetBSD$
#

DISTNAME=	hadoop-lzo
PKGNAME=	${DISTNAME}-0.4.18rc1
CATEGORIES=	archivers

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/twitter/hadoop-lzo
COMMENT=	Refactored version of hadoop-gpl-compression with LZO
LICENSE=	mit

GIT_REPOSITORIES=	hadoop-lzo
GIT_REPO.hadoop-lzo=	git://github.com/twitter/hadoop-lzo.git
GIT_TAG=		master

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

.include "../../joyent/hadoop/Makefile.common"

BUILD_DEPENDS+=		apache-maven>=3:../../devel/apache-maven
DEPENDS+=		hadoop-[0-9]*:../../joyent/hadoop

MAKE_ENV+=		JAVA_HOME=${PKG_JAVA_HOME}			\
			C_INCLUDE_PATH=${BUILDLINK_PREFIX.lzo}/include	\
			LIBRARY_PATH=${BUILDLINK_PREFIX.lzo}/lib

MAKE_ARGS+=		-DskipTests=true

SUBST_CLASSES+=		ldflags
SUBST_STAGE.ldflags=	pre-build
SUBST_MESSAGE.ldflags=	Fixing LDFLAGS
SUBST_FILES.ldflags=	pom.xml
SUBST_VARS.ldflags=	LDFLAGS JAVA_ARCH

INSTALLATION_DIRS+=	lib share/hadoop

BUILD_TARGET=	compile jar

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} mvn clean package ${MAKE_ARGS}

do-test:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} mvn test ${MAKE_ARGS}

do-install:
	cd ${WRKSRC}/target/native/${HADOOP_ARCH}/lib && \
	  ${PAX} -rw -p e * ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/target/hadoop-lzo-0.4.18-SNAPSHOT.jar \
	  ${DESTDIR}${PREFIX}/share/hadoop

.include "../../archivers/lzo/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
