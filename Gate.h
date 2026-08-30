#include "Stage.h"
#include "Notice.h"

class Gate: public Stage {
    public:
        Gate(std::string artist);
        void open() override;
        void close() override;
        void update(const Notice& notice) override;
};