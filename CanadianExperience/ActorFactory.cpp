/**
 * \file ActorFactory.cpp
 *
 * \author Yiteng
 *
 * Abstract base class for actor factories.
 *
 */
#include "pch.h"
#include "ActorFactory.h"

/** Abstract base class for actor factories. 
 * \returns the pointer to the actor*/

std::shared_ptr<CActor> CActorFactory::Create()
{
	return std::shared_ptr<CActor>();
}
