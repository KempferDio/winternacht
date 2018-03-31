#include <Input/Commands/JumpCommand.h>

using namespace Core;

void JumpCommand::execute(GameObject* actor) {
    actor->Jump();
}