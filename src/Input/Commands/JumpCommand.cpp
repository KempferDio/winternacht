#include <Input/Commands/JumpCommand.h>

using namespace Core;

void JumpCommand::execute(GameObjects::Pawn* actor) {
    actor->Jump();
}