#include "Push_location_Plugin.h"
#include "MeshService.h"
#include "configuration.h"
#include "main.h"

#include <assert.h>

// Create an a static instance of our plugin - this registers with the plugin system
ReplyPlugin2 replyPlugin2;

MeshPacket *ReplyPlugin2::allocReply()
{
    assert(currentRequest); // should always be !NULL
    auto req = *currentRequest;
    auto &p = req.decoded.data;
    // The incoming message is in p.payload
    DEBUG_MSG("Received message from=0x%0x, id=%d, msg=%.*s\n", req.from, req.id, p.payload.size, p.payload.bytes);

    screen->print("Sending replyyy\n");

    const char *replyStr = "Message Received, yes";
    auto reply = allocDataPacket();                      // Allocate a packet for sending
    reply->decoded.data.payload.size = strlen(replyStr); // You must specify how many bytes are in the reply
    memcpy(reply->decoded.data.payload.bytes, replyStr, reply->decoded.data.payload.size);

    return reply;
}
