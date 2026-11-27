/* Compatibility plugin for the 2021-02-04 Vidhance core shipped on hanoip (front camera face_stabilizer). */

static const char core_id[] =
    "'39da7b1ebd5c7ba353abea3768f968040329e07b'2021-02-04 16:16:40.395863";
static const char feature[] = "face_stabilizer";

__attribute__((visibility("default")))
void handshake(const char *challenge, char *response, unsigned int capacity)
{
    if (response == 0 || capacity == 0)
        return;

    response[0] = '\0';
    if (challenge == 0 || capacity < sizeof(core_id) - 1 + sizeof(feature))
        return;

    for (unsigned int i = 0; i < sizeof(core_id); ++i) {
        if (challenge[i] != core_id[i])
            return;
    }

    for (unsigned int i = 0; i < sizeof(core_id) - 1; ++i)
        response[i] = challenge[i];
    for (unsigned int i = 0; i < sizeof(feature); ++i)
        response[sizeof(core_id) - 1 + i] = feature[i];
}
