import type { Metadata } from "next";
import "./globals.css";
import { profile } from "@/data/profile";

export const metadata: Metadata = {
  title: `${profile.shortName} | Engenharia de Computação, IoT e Software`,
  description: "Portfólio de Luiz Kramer: sistemas embarcados, IoT, firmware, cloud e aplicações web desenvolvidos de ponta a ponta.",
  keywords: ["Luiz Kramer", "Engenharia de Computação", "IoT", "Sistemas embarcados", "AWS", "ESP32", "Next.js"],
  authors: [{ name: profile.name }],
  openGraph: { title: `${profile.shortName} | Engenharia de Computação e IoT`, description: "Hardware, firmware, comunicação, cloud e software em sistemas completos.", type: "website", locale: "pt_BR" },
};

export default function RootLayout({ children }: LayoutProps<"/">) {
  return (
    <html
      lang="pt-BR"
      suppressHydrationWarning
      className="h-full antialiased"
    >
      <head><script dangerouslySetInnerHTML={{ __html: `try{const t=localStorage.getItem('theme');document.documentElement.dataset.theme=t||(matchMedia('(prefers-color-scheme: dark)').matches?'dark':'light')}catch{}` }} /></head>
      <body className="min-h-full">{children}</body>
    </html>
  );
}
