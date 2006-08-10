/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "activemq/command/RemoveSubscriptionInfo.hpp"

using namespace apache::activemq::command;

/*
 *
 *  Command and marshalling code for OpenWire format for RemoveSubscriptionInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Groovy scripts in the
 *         activemq-core module
 *
 */
RemoveSubscriptionInfo::RemoveSubscriptionInfo()
{
    this->connectionId = NULL ;
    this->subcriptionName = NULL ;
    this->clientId = NULL ;
}

RemoveSubscriptionInfo::~RemoveSubscriptionInfo()
{
}

unsigned char RemoveSubscriptionInfo::getDataStructureType()
{
    return RemoveSubscriptionInfo::TYPE ; 
}

        
p<ConnectionId> RemoveSubscriptionInfo::getConnectionId()
{
    return connectionId ;
}

void RemoveSubscriptionInfo::setConnectionId(p<ConnectionId> connectionId)
{
    this->connectionId = connectionId ;
}

        
p<string> RemoveSubscriptionInfo::getSubcriptionName()
{
    return subcriptionName ;
}

void RemoveSubscriptionInfo::setSubcriptionName(p<string> subcriptionName)
{
    this->subcriptionName = subcriptionName ;
}

        
p<string> RemoveSubscriptionInfo::getClientId()
{
    return clientId ;
}

void RemoveSubscriptionInfo::setClientId(p<string> clientId)
{
    this->clientId = clientId ;
}

int RemoveSubscriptionInfo::marshal(p<IMarshaller> marshaller, int mode, p<IOutputStream> ostream) throw (IOException)
{
    int size = 0 ;

    size += BaseCommand::marshal(marshaller, mode, ostream) ; 
    size += marshaller->marshalObject(connectionId, mode, ostream) ; 
    size += marshaller->marshalString(subcriptionName, mode, ostream) ; 
    size += marshaller->marshalString(clientId, mode, ostream) ; 
    return size ;
}

void RemoveSubscriptionInfo::unmarshal(p<IMarshaller> marshaller, int mode, p<IInputStream> istream) throw (IOException)
{
    BaseCommand::unmarshal(marshaller, mode, istream) ; 
    connectionId = p_cast<ConnectionId>(marshaller->unmarshalObject(mode, istream)) ; 
    subcriptionName = p_cast<string>(marshaller->unmarshalString(mode, istream)) ; 
    clientId = p_cast<string>(marshaller->unmarshalString(mode, istream)) ; 
}
