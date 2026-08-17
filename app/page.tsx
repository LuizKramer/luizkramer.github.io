import { ArrowUpRight, BriefcaseBusiness as Linkedin, CodeXml as Github, Mail, MapPin } from "lucide-react";
import { Header } from "@/components/Header";
import { Academic } from "@/components/sections/Academic";
import { Experience } from "@/components/sections/Experience";
import { Hero } from "@/components/sections/Hero";
import { Projects } from "@/components/sections/Projects";
import { Skills } from "@/components/sections/Skills";
import { SectionTitle } from "@/components/ui/SectionTitle";
import { profile } from "@/data/profile";

export default function Home() {
  return <>
    <Header />
    <main>
      <Hero />
      <section className="section about shell" id="sobre">
        <SectionTitle eyebrow="01 / PERFIL" title="Da placa ao produto." />
        <div className="about-grid"><p>{profile.about}</p><aside><span>FORMAÇÃO</span><strong>Bacharelado em Engenharia de Computação</strong><p>Universidade Tecnológica Federal do Paraná — UTFPR</p><small>Conclusão em 2026 · Pato Branco — PR</small></aside></div>
      </section>
      <Experience />
      <Academic />
      <Projects />
      <Skills />
      <section className="contact-section" id="contato"><div className="shell contact-grid">
        <div><p className="eyebrow">05 / CONTATO</p><h2>Vamos construir<br />algo que funcione<br /><em>no mundo real?</em></h2></div>
        <div className="contact-links">
          <a href={`mailto:${profile.email}`}><Mail size={20}/><span><small>E-MAIL</small>{profile.email}</span><ArrowUpRight size={18}/></a>
          <a href={profile.links.linkedin} target="_blank" rel="noreferrer"><Linkedin size={20}/><span><small>LINKEDIN</small>/in/luizkramer</span><ArrowUpRight size={18}/></a>
          <a href={profile.links.github} target="_blank" rel="noreferrer"><Github size={20}/><span><small>GITHUB</small>/LuizKramer</span><ArrowUpRight size={18}/></a>
          <p><MapPin size={20}/>{profile.location}</p>
        </div>
      </div></section>
    </main>
    <footer className="footer shell"><span>LK.</span><p>© {new Date().getFullYear()} Luiz Kramer</p><a href="#inicio">Voltar ao topo ↑</a></footer>
  </>;
}
