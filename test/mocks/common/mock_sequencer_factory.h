#pragma once

#include "nighthawk/common/factories.h"

#include "gmock/gmock.h"

namespace Nighthawk {

class MockSequencerFactory : public SequencerFactory {
public:
  MockSequencerFactory();
  MOCK_METHOD(SequencerPtr, create,
              (Envoy::TimeSource & time_source, Envoy::Event::Dispatcher& dispatcher,
               const SequencerTarget& sequencer_target,
               TerminationPredicatePtr&& termination_predicate, Envoy::Stats::Scope& scope,
               const Envoy::MonotonicTime scheduled_starting_time),
              (const, override));
};

} // namespace Nighthawk