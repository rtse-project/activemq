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
#include "activemq/command/MessageAck.hpp"

using namespace apache::activemq::command;

/*
 *
 *  Command and marshalling code for OpenWire format for MessageAck
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Groovy scripts in the
 *         activemq-core module
 *
 */
MessageAck::MessageAck()
{
    this->destination = NULL ;
    this->transactionId = NULL ;
    this->consumerId = NULL ;
    this->ackType = 0 ;
    this->firstMessageId = NULL ;
    this->lastMessageId = NULL ;
    this->messageCount = 0 ;
}

MessageAck::~MessageAck()
{
}

unsigned char MessageAck::getDataStructureType()
{
    return MessageAck::TYPE ; 
}

        
p<ActiveMQDestination> MessageAck::getDestination()
{
    return destination ;
}

void MessageAck::setDestination(p<ActiveMQDestination> destination)
{
    this->destination = destination ;
}

        
p<TransactionId> MessageAck::getTransactionId()
{
    return transactionId ;
}

void MessageAck::setTransactionId(p<TransactionId> transactionId)
{
    this->transactionId = transactionId ;
}

        
p<ConsumerId> MessageAck::getConsumerId()
{
    return consumerId ;
}

void MessageAck::setConsumerId(p<ConsumerId> consumerId)
{
    this->consumerId = consumerId ;
}

        
char MessageAck::getAckType()
{
    return ackType ;
}

void MessageAck::setAckType(char ackType)
{
    this->ackType = ackType ;
}

        
p<MessageId> MessageAck::getFirstMessageId()
{
    return firstMessageId ;
}

void MessageAck::setFirstMessageId(p<MessageId> firstMessageId)
{
    this->firstMessageId = firstMessageId ;
}

        
p<MessageId> MessageAck::getLastMessageId()
{
    return lastMessageId ;
}

void MessageAck::setLastMessageId(p<MessageId> lastMessageId)
{
    this->lastMessageId = lastMessageId ;
}

        
int MessageAck::getMessageCount()
{
    return messageCount ;
}

void MessageAck::setMessageCount(int messageCount)
{
    this->messageCount = messageCount ;
}

int MessageAck::marshal(p<IMarshaller> marshaller, int mode, p<IOutputStream> ostream) throw (IOException)
{
    int size = 0 ;

    size += BaseCommand::marshal(marshaller, mode, ostream) ; 
    size += marshaller->marshalObject(destination, mode, ostream) ; 
    size += marshaller->marshalObject(transactionId, mode, ostream) ; 
    size += marshaller->marshalObject(consumerId, mode, ostream) ; 
    size += marshaller->marshalByte(ackType, mode, ostream) ; 
    size += marshaller->marshalObject(firstMessageId, mode, ostream) ; 
    size += marshaller->marshalObject(lastMessageId, mode, ostream) ; 
    size += marshaller->marshalInt(messageCount, mode, ostream) ; 
    return size ;
}

void MessageAck::unmarshal(p<IMarshaller> marshaller, int mode, p<IInputStream> istream) throw (IOException)
{
    BaseCommand::unmarshal(marshaller, mode, istream) ; 
    destination = p_cast<ActiveMQDestination>(marshaller->unmarshalObject(mode, istream)) ; 
    transactionId = p_cast<TransactionId>(marshaller->unmarshalObject(mode, istream)) ; 
    consumerId = p_cast<ConsumerId>(marshaller->unmarshalObject(mode, istream)) ; 
    ackType = (marshaller->unmarshalByte(mode, istream)) ; 
    firstMessageId = p_cast<MessageId>(marshaller->unmarshalObject(mode, istream)) ; 
    lastMessageId = p_cast<MessageId>(marshaller->unmarshalObject(mode, istream)) ; 
    messageCount = (marshaller->unmarshalInt(mode, istream)) ; 
}
