#include <stdio.h>
#include <stdlib.h>

#include <grpc/grpc.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include "cyservice.grpc.pb.h"
#include "cyservice.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using cyservice::Fragment;
using cyservice::CyService;

class CyServiceImpl final : public CyService::Service {

 public:

  Status StreamFragments(ServerContext* context, ServerReaderWriter<Fragment, Fragment>* stream) override {
    Fragment fragment;
    while (stream->Read(&fragment)) {
      stream->Write(fragment);
    }
    return Status::OK;
  }

};

int main (int argc, char *argv[])
{
  std::string server_address("0.0.0.0:8080");
  CyServiceImpl service;
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
  return 0;
}
