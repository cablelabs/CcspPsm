/**********************************************************************
   Copyright [2014] [Cisco Systems, Inc.]
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/


/**********************************************************************

    module:	psm_sysro_interface.c

        For Persistent Storage Manager Implementation (PSM),
        Common Component Software Platform (CCSP)

    ---------------------------------------------------------------

                    Copyright (c) 2011, Cisco Systems, Inc.

                            CISCO CONFIDENTIAL
              Unauthorized distribution or copying is prohibited
                            All rights reserved

 No part of this computer software may be reprinted, reproduced or utilized
 in any form or by any electronic, mechanical, or other means, now known or
 hereafter invented, including photocopying and recording, or using any
 information storage and retrieval system, without permission in writing
 from Cisco Systems, Inc.

    ---------------------------------------------------------------

    description:

        This module implements the some platform-dependent and
        general utility functions for the Psm Sys Registry.

        *   PsmCreateSysRegistry

    ---------------------------------------------------------------

    environment:

        platform independent

    ---------------------------------------------------------------

    author:

        Jian Wu

    ---------------------------------------------------------------

    revision:

        06/17/11    initial revision.

**********************************************************************/


#include "psm_sysro_global.h"


/**********************************************************************

    caller:     component objects

    prototype:

        ANSC_HANDLE
        PsmCreateSysRegistry
            (
                ANSC_HANDLE                 hContainerContext,
                ANSC_HANDLE                 hOwnerContext,
                ANSC_HANDLE                 hAnscReserved
            )

    description:

        This function is called to create a new Sys Registry object.

    argument:   ANSC_HANDLE                 hContainerContext
                This context handle is transparent to the object mapper
                wrapper, it's only meanful to the caller.

                ANSC_HANDLE                 hOwnerContext
                This context handle is transparent to the object mapper
                wrapper, it's only meanful to the caller.

                ANSC_HANDLE                 hAnscReserved
                This context handle is transparent to the object mapper
                wrapper, it's only meanful to the caller.

    return:     handle of the object mapper object.

**********************************************************************/

ANSC_HANDLE
PsmCreateSysRegistry
    (
        ANSC_HANDLE                 hContainerContext,
        ANSC_HANDLE                 hOwnerContext,
        ANSC_HANDLE                 hAnscReserved
    )
{
    ANSC_STATUS                     returnStatus     = ANSC_STATUS_SUCCESS;
    PPSM_SYS_REGISTRY_OBJECT       pPsmSysRegistry = NULL;

    return  PsmSysroCreate(hContainerContext, hOwnerContext, hAnscReserved);
}
