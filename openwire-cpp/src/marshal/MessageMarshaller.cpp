/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "marshal/MessageMarshaller.hpp"

using namespace apache::activemq::client::marshal;

/*
 *  Marshalling code for Open Wire Format for Message
 *
 * NOTE!: This file is autogenerated - do not modify!
 *        if you need to make a change, please see the Groovy scripts in the
 *        activemq-core module
 */

MessageMarshaller::MessageMarshaller()
{
    // no-op
}

MessageMarshaller::~MessageMarshaller()
{
    // no-op
}


    /* 
     * Un-marshal an object instance from the data input stream
     */ 
void MessageMarshaller::unmarshal(ProtocolFormat& wireFormat, Object o, BinaryReader& dataIn, BooleanStream& bs) 
{
    base.unmarshal(wireFormat, o, dataIn, bs);

    Message& info = (Message&) o;
        info.setProducerId((org.apache.activemq.command.ProducerId) tightUnmarsalCachedObject(wireFormat, dataIn, bs));
        info.setDestination((org.apache.activemq.command.ActiveMQDestination) tightUnmarsalCachedObject(wireFormat, dataIn, bs));
        info.setTransactionId((org.apache.activemq.command.TransactionId) tightUnmarsalCachedObject(wireFormat, dataIn, bs));
        info.setOriginalDestination((org.apache.activemq.command.ActiveMQDestination) tightUnmarsalCachedObject(wireFormat, dataIn, bs));
        info.setMessageId((org.apache.activemq.command.MessageId) tightUnmarsalNestedObject(wireFormat, dataIn, bs));
        info.setOriginalTransactionId((org.apache.activemq.command.TransactionId) tightUnmarsalCachedObject(wireFormat, dataIn, bs));
        info.setGroupID(tightUnmarshalString(dataIn, bs));
        info.setGroupSequence(dataIn.readInt());
        info.setCorrelationId(tightUnmarshalString(dataIn, bs));
        info.setPersistent(bs.readBoolean());
        info.setExpiration(tightUnmarshalLong(wireFormat, dataIn, bs));
        info.setPriority(dataIn.readByte());
        info.setReplyTo((org.apache.activemq.command.ActiveMQDestination) tightUnmarsalNestedObject(wireFormat, dataIn, bs));
        info.setTimestamp(tightUnmarshalLong(wireFormat, dataIn, bs));
        info.setType(tightUnmarshalString(dataIn, bs));
        info.setContent(tightUnmarshalByteSequence(dataIn, bs));
        info.setMarshalledProperties(tightUnmarshalByteSequence(dataIn, bs));
        info.setDataStructure((org.apache.activemq.command.DataStructure) tightUnmarsalNestedObject(wireFormat, dataIn, bs));
        info.setTargetConsumerId((org.apache.activemq.command.ConsumerId) tightUnmarsalCachedObject(wireFormat, dataIn, bs));
        info.setCompressed(bs.readBoolean());
        info.setRedeliveryCounter(dataIn.readInt());

        if (bs.readBoolean()) {
            short size = dataIn.readShort();
            org.apache.activemq.command.BrokerId value[] = new org.apache.activemq.command.BrokerId[size];
            for( int i=0; i < size; i++ ) {
                value[i] = (org.apache.activemq.command.BrokerId) tightUnmarsalNestedObject(wireFormat,dataIn, bs);
            }
            info.setBrokerPath(value);
        }
        else {
            info.setBrokerPath(null);
        }
        info.setArrival(tightUnmarshalLong(wireFormat, dataIn, bs));
        info.setUserID(tightUnmarshalString(dataIn, bs));
        info.setRecievedByDFBridge(bs.readBoolean());

}


/*
 * Write the booleans that this object uses to a BooleanStream
 */
int MessageMarshaller::marshal1(ProtocolFormat& wireFormat, Object& o, BooleanStream& bs) {
    Message& info = (Message&) o;

    int rc = base.marshal1(wireFormat, info, bs);
    rc += marshal1CachedObject(wireFormat, info.getProducerId(), bs);
    rc += marshal1CachedObject(wireFormat, info.getDestination(), bs);
    rc += marshal1CachedObject(wireFormat, info.getTransactionId(), bs);
    rc += marshal1CachedObject(wireFormat, info.getOriginalDestination(), bs);
    rc += marshal1NestedObject(wireFormat, info.getMessageId(), bs);
    rc += marshal1CachedObject(wireFormat, info.getOriginalTransactionId(), bs);
    rc += writeString(info.getGroupID(), bs);
        rc += writeString(info.getCorrelationId(), bs);
    bs.writeBoolean(info.isPersistent());
    rc += marshal1Long(wireFormat, info.getExpiration(), bs);
        rc += marshal1NestedObject(wireFormat, info.getReplyTo(), bs);
    rc += marshal1Long(wireFormat, info.getTimestamp(), bs);
    rc += writeString(info.getType(), bs);
    bs.writeBoolean(info.getContent()!=null);
    rc += info.getContent()==null ? 0 : info.getContent().Length+4;
    bs.writeBoolean(info.getMarshalledProperties()!=null);
    rc += info.getMarshalledProperties()==null ? 0 : info.getMarshalledProperties().Length+4;
    rc += marshal1NestedObject(wireFormat, info.getDataStructure(), bs);
    rc += marshal1CachedObject(wireFormat, info.getTargetConsumerId(), bs);
    bs.writeBoolean(info.isCompressed());
        rc += marshalObjectArray(wireFormat, info.getBrokerPath(), bs);
    rc += marshal1Long(wireFormat, info.getArrival(), bs);
    rc += writeString(info.getUserID(), bs);
    bs.writeBoolean(info.isRecievedByDFBridge());

    return rc + 3;
}

/* 
 * Write a object instance to data output stream
 */
void MessageMarshaller::marshal2(ProtocolFormat& wireFormat, Object& o, BinaryWriter& dataOut, BooleanStream& bs) {
    base.marshal2(wireFormat, o, dataOut, bs);

    Message& info = (Message&) o;
    marshal2CachedObject(wireFormat, info.getProducerId(), dataOut, bs);
    marshal2CachedObject(wireFormat, info.getDestination(), dataOut, bs);
    marshal2CachedObject(wireFormat, info.getTransactionId(), dataOut, bs);
    marshal2CachedObject(wireFormat, info.getOriginalDestination(), dataOut, bs);
    marshal2NestedObject(wireFormat, info.getMessageId(), dataOut, bs);
    marshal2CachedObject(wireFormat, info.getOriginalTransactionId(), dataOut, bs);
    writeString(info.getGroupID(), dataOut, bs);
    DataStreamMarshaller.writeInt(info.getGroupSequence(), dataOut);
    writeString(info.getCorrelationId(), dataOut, bs);
    bs.readBoolean();
    marshal2Long(wireFormat, info.getExpiration(), dataOut, bs);
    DataStreamMarshaller.writeByte(info.getPriority(), dataOut);
    marshal2NestedObject(wireFormat, info.getReplyTo(), dataOut, bs);
    marshal2Long(wireFormat, info.getTimestamp(), dataOut, bs);
    writeString(info.getType(), dataOut, bs);
    if(bs.readBoolean()) {
       DataStreamMarshaller.writeInt(info.getContent().Length, dataOut);
       dataOut.write(info.getContent());
    }
    if(bs.readBoolean()) {
       DataStreamMarshaller.writeInt(info.getMarshalledProperties().Length, dataOut);
       dataOut.write(info.getMarshalledProperties());
    }
    marshal2NestedObject(wireFormat, info.getDataStructure(), dataOut, bs);
    marshal2CachedObject(wireFormat, info.getTargetConsumerId(), dataOut, bs);
    bs.readBoolean();
    DataStreamMarshaller.writeInt(info.getRedeliveryCounter(), dataOut);
    marshalObjectArray(wireFormat, info.getBrokerPath(), dataOut, bs);
    marshal2Long(wireFormat, info.getArrival(), dataOut, bs);
    writeString(info.getUserID(), dataOut, bs);
    bs.readBoolean();

}
