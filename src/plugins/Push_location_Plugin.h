#pragma once
#include "SinglePortPlugin.h"


/**
 * A simple example plugin that just replies with "Message received" to any message it receives.
 */
class Push_Location_Plugin : public SinglePortPlugin
{
  public:
    /** Constructor
     * name is for debugging output
     */
    Push_Location_Plugin() : SinglePortPlugin("reply", PortNum_PRIVATE_APP) {}

  protected:

    /** For reply plugin we do all of our processing in the (normally optional)
     * want_replies handling
    */
    virtual MeshPacket *allocReply();
};
