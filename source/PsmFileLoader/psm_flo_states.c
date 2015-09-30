/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

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

    module: psm_flo_states.c

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

        This module implements the advanced state-access functions
        of the Psm File Loader Object.

        *   PsmFloGetPsmCfmIf
        *   PsmFloSetPsmCfmIf
        *   PsmFloGetSysIraIf
        *   PsmFloSetSysIraIf
        *   PsmFloGetProperty
        *   PsmFloSetProperty
        *   PsmFloResetProperty
        *   PsmFloReset

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


#include "psm_flo_global.h"


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_HANDLE
        PsmFloGetPsmCfmIf
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to retrieve Psm Cfm Interface.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     the interface.

**********************************************************************/

ANSC_HANDLE
PsmFloGetPsmCfmIf
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT)hThisObject;

    return  pMyObject->hPsmCfmIf;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        PsmFloSetPsmCfmIf
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hInterface
            );

    description:

        This function is called to set Psm Cfm Interface.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hInterface
                The input interface.

    return:     the state of the operation.

**********************************************************************/

ANSC_STATUS
PsmFloSetPsmCfmIf
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInterface
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT)hThisObject;

    pMyObject->hPsmCfmIf = hInterface;

    return ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_HANDLE
        PsmFloGetSysIraIf
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to retrieve System Ira Interface

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     the interface.

**********************************************************************/

ANSC_HANDLE
PsmFloGetSysIraIf
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT)hThisObject;

    return  pMyObject->hSysIraIf;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        PsmFloSetSysIraIf
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hInterface
            );

    description:

        This function is called to set Sys Ira interface.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hInterface
                The  input interface

    return:     the state of the operation.

**********************************************************************/

ANSC_STATUS
PsmFloSetSysIraIf
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hInterface
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT)hThisObject;

    pMyObject->hSysIraIf = hInterface;

    return ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        PsmFloGetProperty
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hProperty
            );

    description:

        This function is called to retrieve object property.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hProperty
                Specifies the property data structure to be filled.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
PsmFloGetProperty
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hProperty
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT  )hThisObject;
    PPSM_FILE_LOADER_PROPERTY       pProperty    = (PPSM_FILE_LOADER_PROPERTY)&pMyObject->Property;

    *(PPSM_FILE_LOADER_PROPERTY)hProperty = *pProperty;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        PsmFloSetProperty
            (
                ANSC_HANDLE                 hThisObject,
                ANSC_HANDLE                 hProperty
            );

    description:

        This function is called to configure object property.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

                ANSC_HANDLE                 hProperty
                Specifies the property data structure to be copied.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
PsmFloSetProperty
    (
        ANSC_HANDLE                 hThisObject,
        ANSC_HANDLE                 hProperty
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT  )hThisObject;
    PPSM_FILE_LOADER_PROPERTY       pProperty    = (PPSM_FILE_LOADER_PROPERTY)&pMyObject->Property;

    *pProperty = *(PPSM_FILE_LOADER_PROPERTY)hProperty;

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        PsmFloResetProperty
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to reset object property.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
PsmFloResetProperty
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT  )hThisObject;
    PPSM_FILE_LOADER_PROPERTY       pProperty    = (PPSM_FILE_LOADER_PROPERTY)&pMyObject->Property;

    AnscZeroMemory(pProperty, sizeof(PSM_FILE_LOADER_PROPERTY));

    return  ANSC_STATUS_SUCCESS;
}


/**********************************************************************

    caller:     owner of this object

    prototype:

        ANSC_STATUS
        PsmFloReset
            (
                ANSC_HANDLE                 hThisObject
            );

    description:

        This function is called to reset object states.

    argument:   ANSC_HANDLE                 hThisObject
                This handle is actually the pointer of this object
                itself.

    return:     status of operation.

**********************************************************************/

ANSC_STATUS
PsmFloReset
    (
        ANSC_HANDLE                 hThisObject
    )
{
    ANSC_STATUS                     returnStatus = ANSC_STATUS_SUCCESS;
    PPSM_FILE_LOADER_OBJECT         pMyObject    = (PPSM_FILE_LOADER_OBJECT  )hThisObject;
    PPSM_FILE_LOADER_PROPERTY       pProperty    = (PPSM_FILE_LOADER_PROPERTY)&pMyObject->Property;

    return  ANSC_STATUS_SUCCESS;
}
