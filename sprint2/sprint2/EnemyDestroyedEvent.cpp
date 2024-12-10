#include "EnemyDestroyedEvent.h"

void EnemyDestroyedEvent::addListener(const Listener& listener) {
	Listeners.push_back(listener);
}
void EnemyDestroyedEvent::trigger() {
	cout << "ede trigger() \n";
	for (const auto& listener : Listeners) {
		listener();
	}
}

//issue with this & xmemory
/*		void removeListener(const Listener& listener) {
			listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
		}*/