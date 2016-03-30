//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2014-2015, Lawrence Livermore National Security, LLC.
// 
// Produced at the Lawrence Livermore National Laboratory
// 
// LLNL-CODE-666778
// 
// All rights reserved.
// 
// This file is part of Conduit. 
// 
// For details, see: http://llnl.github.io/conduit/.
// 
// Please also read conduit/LICENSE
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright notice, 
//   this list of conditions and the disclaimer below.
// 
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the disclaimer (as noted below) in the
//   documentation and/or other materials provided with the distribution.
// 
// * Neither the name of the LLNS/LLNL nor the names of its contributors may
//   be used to endorse or promote products derived from this software without
//   specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
// LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//-----------------------------------------------------------------------------
///
/// file: conduit_web_visualizer.hpp
///
//-----------------------------------------------------------------------------

#ifndef CONDUIT_WEB_VISUALIZER_HPP
#define CONDUIT_WEB_VISUALIZER_HPP

//-----------------------------------------------------------------------------
// conduit lib includes
//-----------------------------------------------------------------------------
#include "conduit.hpp"
#include "Conduit_IO_Exports.hpp"

#include "conduit_web.hpp"

//-----------------------------------------------------------------------------
// -- begin conduit:: --
//-----------------------------------------------------------------------------
namespace conduit
{

//-----------------------------------------------------------------------------
// -- begin conduit::io --
//-----------------------------------------------------------------------------

namespace io 
{

//-----------------------------------------------------------------------------
// -- Visualizer Web Request Handler  -
//-----------------------------------------------------------------------------
class CONDUIT_IO_API VisualizerRequestHandler : public WebRequestHandler
{
public:
                   VisualizerRequestHandler(Node *node);
                  ~VisualizerRequestHandler();
    
    virtual bool   handle_post(WebServer *server,
                               struct mg_connection *conn);

    virtual bool   handle_get(WebServer *server,
                              struct mg_connection *conn);

private:
    // catch all, used for any post or get
    bool           handle_request(WebServer *server,
                                  struct mg_connection *conn);
    // handlers for specific commands 
    bool           handle_get_schema(struct mg_connection *conn);
    bool           handle_get_value(struct mg_connection *conn);
    bool           handle_get_base64_json(struct mg_connection *conn);
    bool           handle_shutdown(WebServer *server);

    // holds the node to visualize 
    Node          *m_node;
};

//-----------------------------------------------------------------------------
// -- Visualizer Web Request Handler  -
//-----------------------------------------------------------------------------

class CONDUIT_IO_API VisualizerServer
{
public:
    static WebServer  *serve(Node *data,
                             bool block=false,
                             index_t port = 8080,
                             const std::string &ssl_cert_file = std::string(""));
};


}
//-----------------------------------------------------------------------------
// -- end conduit::io --
//-----------------------------------------------------------------------------



}
//-----------------------------------------------------------------------------
// -- end conduit:: --
//-----------------------------------------------------------------------------

#endif 



