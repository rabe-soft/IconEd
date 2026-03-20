##############################################################################
#
# PROJECT:      
#               Local Makefile
# FILE:         LOCAL.MK
#               Ported to GOC by RABE-Soft 07/2025
#
# AUTHOR:       Rainer Bettsteller
#
##############################################################################


# XGOCFLAGS werden an dan GOC-Pre-Prozessor Åbergeben


# Keine EC-Version anlegen - Do not Create any EC version
# NO_EC = 1


# XCCOMFLAGS werden an den C-Compiler Åbergeben


# LINKFLAGS werden an den GLUE-Linker Åbergeben

# Create a Copyrigth-notice
LINKFLAGS += -N Made\20by\20RABE-Soft\2007/2025

#include <$(SYSMAKEFILE)>

