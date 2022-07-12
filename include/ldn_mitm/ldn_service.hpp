#pragma once
#include <cstring>
#include <atomic>

#include <stratosphere.hpp>
#include <switch.h>

#include "logging.hpp"
#include "interfaces/iuservice.hpp"
#include "ldn_userlocalcommunication.hpp"
#include "ldn_shim.hpp"

namespace ams::mitm::ldn
{
    class LdnUMitmService : public sf::MitmServiceImplBase
    {
    public:
        using MitmServiceImplBase::MitmServiceImplBase;

    public:
        static bool ShouldMitm(const sm::MitmProcessInfo &client_info)
        {
            log::DEBUG_LOG("should_mitm pid: %" PRIu64 " tid: %" PRIx64, client_info.process_id, client_info.program_id);
            return true;
        }

    public:
        /* Overridden commands. */
        Result CreateUserLocalCommunicationService(sf::Out<sf::SharedPointer<IUserLocalCommunicationInterface>> out);
    };
    static_assert(ams::mitm::ldn::IsILdnUMitmInterface<LdnUMitmService>);
}
