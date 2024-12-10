#pragma once
#include "utils.h"

class EnemyDestroyedEvent {

	private:
		using Listener = function<void()>;
		vector<Listener> Listeners;

	public:
		void addListener(const Listener& listener);
		void trigger();
		//issue with this & xmemory
		/*		void removeListener(const Listener& listener) {
				listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
			}*/
};