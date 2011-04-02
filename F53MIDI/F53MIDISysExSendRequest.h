/**

@author  Kurt Revis, Christopher Ashworth
@file    F53MIDISysExSendRequest.h
@date    Created on 4/07/06.
@brief   

Copyright (c) 2001-2004, Kurt Revis.  All rights reserved.
Copyright (c) 2006 Christopher Ashworth. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* Neither the name of Kurt Revis, nor Snoize, nor the names of other contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**/

#import <Foundation/Foundation.h>
#import <CoreMIDI/CoreMIDI.h>

@class F53MIDIDestinationEndpoint, F53MIDISystemExclusiveMessage;


@interface F53MIDISysExSendRequest : NSObject
{
    MIDISysexSendRequest _request;
    NSData *_fullMessageData;
    F53MIDISystemExclusiveMessage *_message;
}

+ (F53MIDISysExSendRequest *) sysExSendRequestWithMessage: (F53MIDISystemExclusiveMessage *) aMessage 
												endpoint: (F53MIDIDestinationEndpoint *) endpoint;

- (id) initWithMessage: (F53MIDISystemExclusiveMessage *) aMessage endpoint: (F53MIDIDestinationEndpoint *) endpoint;

- (F53MIDISystemExclusiveMessage *) message;

- (void) send;
- (BOOL) cancel;

- (unsigned int) bytesRemaining;
- (unsigned int) totalBytes;
- (unsigned int) bytesSent;
- (BOOL) wereAllBytesSent;

@end

// Notifications
extern NSString *F53MIDISysExSendRequestFinishedNotification;