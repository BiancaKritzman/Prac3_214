#include "Stage.h"
#include "Notice.h"

class Gate: public Stage {
    public:
        void open() override;
        void close() override;
        void update(const Notice& notice) override;
};