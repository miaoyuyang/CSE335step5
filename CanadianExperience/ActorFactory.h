/**
 * \file ActorFactory.h
 *
 * \author Yiteng Zhang
 *
 * Abstract base class for actor factories.
 */
#pragma once
#include "Actor.h"
#include <memory>

 /**
  * Abstract base class for actor factories.
  */
class CActorFactory
{
public:
    /** Abstract base class for actor factories. */
    std::shared_ptr<CActor> CActorFactory::Create();
};

