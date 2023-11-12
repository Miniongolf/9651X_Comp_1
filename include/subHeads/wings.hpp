#include "main.h"

class Wings {
    private:    
        bool leftIsExtended = false, rightIsExtended = false;

    public:
        /**
         * Wings class constructor (no args)
         * \param None
         */
        Wings();

        /**
         * Returns the piston positions
         * \param None
         * \returns Wings positions as bool (`leftIsExtended`, `rightIsExtended`)
         */
        std::array<bool,2> getStatus();

        /**
         * Sets the position for pneumatics
         * \param leftPos
         *        (1 = extend | -1 = retract | 0 = stay)
         * \param rightPos
         *        (1 = extend | -1 = retract | 0 = stay)
         * \returns `None`
         */
        void setPosition(int leftPos, int rightPos);

        /**
         * Sets the position for the pneumatics
         * \param bothPos
         *        1 = extend | -1 = retract | 0 = stay
         * \returns `None`
         * \overload setPosition(leftPos, rightPos)
         */
        void setPosition(int bothPos);
};